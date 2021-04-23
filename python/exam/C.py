def readList(file):
    return list(map(int, file.readline().split()))


def printTransposed(wrdList, rng, file):
    for i in range(rng):
        for el in wrdList:
            file.write(el[i] + '\t')
        file.write('\n')


def paste(file, outFile):
    m = int(file.readline())
    totalList = []
    maxWords = 0
    for i in range(m):
        n = int(file.readline())
        curList = []
        for j in range(n):
            curList.append(file.readline().strip())
        totalList.append(curList)
        for el in totalList:
            if len(el) > maxWords:
                maxWords = len(el)
        for el in totalList:
            if len(el) < maxWords:
                for cnt in range(len(el), maxWords):
                    el.append('')
    printTransposed(totalList, maxWords, outFile)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        paste(inFile, outFile)
    inFile.close()
    outFile.close()


main()
