import sys


def readIntList(file):
    return list(map(int, file.readline().split()))


def countMostCommon(intList):
    mostCommonElement = intList[0]
    maxCount = 0
    for element in intList:
        if intList.count(element) > maxCount:
            maxCount = intList.count(element)
            mostCommonElement = element
    return mostCommonElement


def printIntResult(result):
    print(result)


def main():
    intList = readIntList(sys.stdin)
    printIntResult(countMostCommon(intList))


main()
