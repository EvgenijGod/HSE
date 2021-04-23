x1 = float(input())
y1 = float(input())


def IsPointInSquare(x, y):
    return -1 <= x <= 1 and -1 <= y <= 1


if (IsPointInSquare(x1, y1)):
    print('YES')
else:
    print('NO')
