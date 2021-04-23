a = int(input())


def printSquare(a):
    if a != 0:
        printSquare(int(input()))
        if a ** 0.5 == int(a ** 0.5):
            print(a, end=' ')
            return 1
    return 0


if printSquare(a) == 1:
    printSquare(a)
else:
    print(0)
