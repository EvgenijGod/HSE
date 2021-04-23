def readList(file):
    return list(map(int, file.readline().split()))


def printList(resList, file):
    for el in resList:
        file.write(str(el) + '\n')


def readDict(file):
    ##input: length \n key el el el...
    dictLen = int(file.readline())
    keyDict = {}
    for i in range(dictLen):
        line = list(file.readline().split())
        keyDict[line[0]] = []
        for j in range(1, len(line)):
            keyDict[line[0]].append(line[j])
    return keyDict


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        pass
        ##tmpList = readList(inFile)
        ##printList(tmpList, outFile)
    inFile.close()
    outFile.close()


main()
