import sys


def readIntList(file):
    return list(map(int, file.readline().split()))


def insertElement(intList, position, elValue):
    if position == len(intList):
        intList.append(elValue)
        return intList
    lastEl = intList[-1]
    for i in range(len(intList) - 1, position, -1):
        intList[i] = intList[i - 1]
    intList[position] = elValue
    intList.append(lastEl)
    return intList


def printIntList(myList):
    for element in myList:
        print(element, end=' ')


def main():
    intList = readIntList(sys.stdin)
    posAndValue = readIntList(sys.stdin)
    k = posAndValue[0]
    c = posAndValue[1]
    result = insertElement(intList, k, c)
    printIntList(result)


main()
