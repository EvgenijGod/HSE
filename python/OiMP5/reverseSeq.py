a = int(input())


def printBackwards(a):
    if a == 0:
        print(0)
        return a
    printBackwards(int(input()))
    print(a)


printBackwards(a)
