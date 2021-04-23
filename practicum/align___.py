import numpy as np
from skimage.transform import pyramid_gaussian
from skimage.io import imread, imshow, imsave
from skimage import img_as_float
import matplotlib.pyplot as plt

def get_shifts (channel_a, channel_b, row_shift_range, col_shift_range):
    min_row_shift, max_row_shift = row_shift_range
    min_col_shift, max_col_shift = col_shift_range
    
    direction = -1
    
    max_corr = None
    best_row_shift = 0
    best_col_shift = 0
    
    a_shifted = np.roll(channel_a, min_row_shift - 1, axis=0)
    a_shifted = np.roll(a_shifted, min_col_shift - 1, axis=1)
    
    for row_shift in range(min_row_shift, max_row_shift + 1):
        a_shifted = np.roll(a_shifted,1,axis=0)

        direction = -direction
        
        if direction == -1:
            min_col_shift, max_col_shift = max_col_shift, min_col_shift
        
        for col_shift in range(min_col_shift, max_col_shift + direction,direction):
            a_shifted = np.roll(a_shifted,direction,axis=1)
            
            a_list = a_shifted.flatten()
            b_list = channel_b.flatten()
            
            cur_corr = np.sum((a_list * b_list)) / (np.sqrt((np.sum(a_list**2)) * (np.sum(b_list**2))))
            
            if max_corr == None or max_corr < cur_corr:
                max_corr = cur_corr
                best_row_shift = row_shift
                best_col_shift = col_shift
            
        if direction == -1:
            min_col_shift, max_col_shift = max_col_shift, min_col_shift
    
    return (best_row_shift, best_col_shift)

def pyramid_search(channel_a, channel_b):
    if channel_a.shape[0] < 1000:
        depth = 2
    else:
        depth = 5
    pyramid_a = tuple(pyramid_gaussian(channel_a, max_layer=depth,downscale=2,multichannel=False))
    pyramid_b = tuple(pyramid_gaussian(channel_b, max_layer=depth,downscale=2,multichannel=False))
    
    row_shift_range = (-15,15)
    col_shift_range = (-15,15)
    
    for current_a, current_b in reversed(list(zip(pyramid_a, pyramid_b))):
        cur_shift = get_shifts(current_a, current_b, row_shift_range, col_shift_range)
        row_shift_range = (cur_shift[0] * 2 - 1, cur_shift[0] * 2 + 1)
        col_shift_range = (cur_shift[1] * 2 - 1, cur_shift[1] * 2 + 1)
    
    return cur_shift

def align (img, g_coord):
    img = img_as_float(img)
    row_g, col_g = g_coord
    img_h, img_w = img.shape
    
    channel_h = img_h // 3
    b = img[:channel_h,]
    g = img[channel_h:channel_h * 2,]
    r = img[channel_h * 2:channel_h * 3,]
    
    vert_edge = int(channel_h * 0.1)
    hor_edge = int(img_w * 0.1)
    b = b[vert_edge:-vert_edge,hor_edge:-hor_edge]
    g = g[vert_edge:-vert_edge,hor_edge:-hor_edge]
    r = r[vert_edge:-vert_edge,hor_edge:-hor_edge]
    
    shift_y_b, shift_x_b = pyramid_search(b,g)
    shift_y_r, shift_x_r = pyramid_search(r,g)
    
    b = np.roll(b,shift_y_b,axis=0)
    b = np.roll(b,shift_x_b,axis=1)
    r = np.roll(r,shift_y_r,axis=0)
    r = np.roll(r,shift_x_r,axis=1)
    
    #print(shift_y_r,shift_x_r,shift_y_b,shift_x_b)
    dest = np.dstack((r,g,b))
    #imshow(dest)
    
    row_b = row_g - shift_y_b - channel_h
    col_b = col_g - shift_x_b
    row_r = row_g - shift_y_r + channel_h
    col_r = col_g - shift_x_r
    
    return dest, (row_b, col_b), (row_r, col_r)
