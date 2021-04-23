x1 = float(input())
y1 = float(input())


def IsPointInSquare(x, y):
    return -x - 1 <= y <= -x + 1 and x - 1 <= y <= x + 1


if (IsPointInSquare(x1, y1)):
    print('YES')
else:
    print('NO')
