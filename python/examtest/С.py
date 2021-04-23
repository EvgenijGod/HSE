def readList(file):
    lenList = int(file.readline())
    resList = []
    for i in range(lenList):
        resList.append(file.readline().strip())
    return resList


def checkNum(wtnss, sspct):
    for char in wtnss:
        if char not in sspct:
            return False
    return True


def findSspct(sspctList, wtnssList):
    maxWtnss = 0
    resList = []
    for suspect in sspctList:
        cntWtnss = 0
        for witness in wtnssList:
            if checkNum(witness, suspect):
                cntWtnss += 1
        if cntWtnss == maxWtnss:
            resList.append(suspect.strip())
        elif cntWtnss > maxWtnss:
            maxWtnss = cntWtnss
            resList = [suspect.strip()]
    return resList


def printList(outList, file):
    for el in outList:
        file.write(el + '\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        wtnssList = readList(inFile)
        sspctList = readList(inFile)
        printList(findSspct(sspctList, wtnssList), outFile)
    inFile.close()
    outFile.close()


main()
