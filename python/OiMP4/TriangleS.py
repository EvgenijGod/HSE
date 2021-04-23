a = float(input())
b = float(input())
c = float(input())
p = (a + b + c) / 2
triSquare = (p * (p - a) * (p - b) * (p - c)) ** 0.5
if triSquare == int(triSquare):
    print(int(triSquare))
else:
    print('{:.6}'.format(triSquare))
