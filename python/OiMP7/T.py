import sys


def readIntList(file):
    return list(map(int, file.readline().split()))


def listUniqueElements(intList):
    result = []
    for element in intList:
        if intList.count(element) == 1:
            result.append(element)
    return result


def printListResult(resList):
    for element in resList:
        print(element)


def main():
    intList = readIntList(sys.stdin)
    printListResult(listUniqueElements(intList))


main()
