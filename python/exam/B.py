def readList(file):
    return list(map(int, file.readline().split()))


def printList(resList, file):
    for el in resList:
        file.write(str(el) + '\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        pass
        ##tmpList = readList(inFile)
        ##printList(tmpList, outFile)
    inFile.close()
    outFile.close()


main()
