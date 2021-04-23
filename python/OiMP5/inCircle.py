x1 = float(input())
y1 = float(input())
xc1 = float(input())
yc1 = float(input())
r1 = float(input())


def IsPointInCircle(x, y, xc, yc, r):
    return (x - xc) ** 2 + (y - yc) ** 2 <= r ** 2


if (IsPointInCircle(x1, y1, xc1, yc1, r1)):
    print('YES')
else:
    print('NO')
