def readString(file):
    n = int(file.readline())
    string = file.readline()
    return n, string


def countEl(letters):
    cntArr = [0] * 26
    for letter in letters:
        cntArr[ord(letter) - 65] += 1
    return cntArr


def palindrome(letters):
    cntLetters = countEl(letters)
    pldrm = ''
    for i in range(26):
        while cntLetters[i] >= 2:
            pldrm += chr(i + 65)
            cntLetters[i] -= 2
    if 1 in cntLetters:
        center = chr(cntLetters.index(1) + 65)
    else:
        center = ''
    return pldrm + center + pldrm[::-1]


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, letters = readString(inFile)
        outFile.write(palindrome(letters))
    inFile.close()
    outFile.close()


main()
