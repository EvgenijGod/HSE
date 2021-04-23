def countEl(letters):
    cntArr = [0] * 61
    signArray = sorted(['!', '(', ')', ',', '-', '.', ':', ';', '?'])
    for letter in letters:
        if letter in signArray:
            ind = signArray.index(letter)
            cntArr[ind] += 1
        elif 64 < ord(letter) < 91:
            cntArr[ord(letter) - 56] += 1
        elif 96 < ord(letter) < 123:
            cntArr[ord(letter) - 62] += 1
    return cntArr


def findMax(arr):
    max = arr[0]
    for i in range(len(arr)):
        if arr[i] > max:
            max = arr[i]
    return max


def getChar(ind):
    signArray = sorted(['!', '(', ')', ',', '-', '.', ':', ';', '?'])
    if -1 < ind < 9:
        return signArray[ind]
    elif ind < 35:
        return chr(ind + 56)
    else:
        return chr(ind + 62)


def histogram(line, file):
    cntArr = countEl(line)
    shortArr = []
    for i in range(61):
        if cntArr[i] != 0:
            shortArr.append(cntArr[i])
    maxEl = findMax(shortArr)
    while maxEl != 0:
        for i in range(len(shortArr)):
            if shortArr[i] == maxEl:
                file.write('#')
                shortArr[i] -= 1
            else:
                file.write(' ')
        file.write('\n')
        maxEl = findMax(shortArr)
    for j in range(len(cntArr)):
        if cntArr[j] != 0:
            char = getChar(j)
            file.write(char)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        line = inFile.read()
        histogram(line, outFile)
    inFile.close()
    outFile.close()


main()
