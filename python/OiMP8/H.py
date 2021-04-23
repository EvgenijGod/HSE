import sys


def readIntList(file):
    return list(map(int, file.readline().split()))


def sortList(intList):
    return sorted(intList)


def printRes(intList, listLen):
    for i in range(listLen):
        print(intList[i], end=' ')


def main():
    listLen = int(sys.stdin.readline())
    intList = readIntList(sys.stdin)
    sortedList = sortList(intList)
    printRes(sortedList, listLen)


main()
