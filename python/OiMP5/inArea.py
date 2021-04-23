x1 = float(input())
y1 = float(input())


def IsPointInArea(x, y):
    area1 = (x + 1) ** 2 + (y - 1) ** 2 <= 4 and -x <= y and y >= 2 * x + 2
    area2 = (x + 1) ** 2 + (y - 1) ** 2 >= 4 and y <= -x and y <= 2 * x + 2
    return area1 or area2


if(IsPointInArea(x1, y1)):
    print('YES')
else:
    print('NO')
