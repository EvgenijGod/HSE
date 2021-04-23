import sys


def readLine(file):
    return list(map(int, file.readline().split()))


def returnRemainingKegels(listKegel, leftKegel, rightKegel):
    fallenKegs = '.' * (rightKegel - leftKegel + 1)
    listKegel = listKegel[:leftKegel] + fallenKegs + listKegel[rightKegel + 1:]
    return listKegel


def doFunctionMultipleTimes(numberOfKegels, numberOfRolls):
    listKegel = 'I' * numberOfKegels
    for i in range(numberOfRolls):
        fallenKegels = readLine(sys.stdin)
        leftKegel = fallenKegels[0] - 1
        rightKegel = fallenKegels[1] - 1
        listKegel = returnRemainingKegels(listKegel, leftKegel, rightKegel)
    return listKegel


def printRes(listKegel):
    print(listKegel)


def main():
    n, k = readLine(sys.stdin)
    printRes(doFunctionMultipleTimes(n, k))


main()
