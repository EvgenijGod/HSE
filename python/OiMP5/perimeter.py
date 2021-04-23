x1 = float(input())
y1 = float(input())
x2 = float(input())
y2 = float(input())
x3 = float(input())
y3 = float(input())


def dist(a1, b1, a2, b2):
    return ((a2 - a1) ** 2 + (b2 - b1) ** 2) ** 0.5


perimeter = dist(x1, y1, x2, y2) + dist(x1, y1, x3, y3) + dist(x2, y2, x3, y3)
if perimeter == int(perimeter):
    print(int(perimeter))
else:
    print('{:.6}'.format(perimeter))
