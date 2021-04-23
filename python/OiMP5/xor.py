firstNum = int(input())
secondNum = int(input())


def xor(x, y):
    if x == y:
        return 0
    else:
        return 1


print(xor(firstNum, secondNum))
