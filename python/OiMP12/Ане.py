def construstMinor(mtrx, im, jm, n, m):
    ##n, m - size of matrix; im, jm - убирающиеся строка и столбец
    resMtrx = []
    for i in range(n):
        ##print('i:', i)
        if i != im:
            row = []
            for j in range(m):
                ##print('j:', j)
                if j != jm:
                    ##print(mtrx[i][j])
                    row.append(mtrx[i][j])
            ##print(row)
            resMtrx.append(row)
    return resMtrx


matrix = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
print(construstMinor(matrix, 1, 2, 3, 3))
