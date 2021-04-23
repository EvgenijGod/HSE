def hasThreeSimilarDigits(num):
    digitList = []
    n = num
    while n > 0:
        digitList.append(n % 10)
        n //= 10
    for digit in digitList:
        if digitList.count(digit) == 3:
            return True
    return False


def printNum(left, right, file):
    for i in range(left, right + 1):
        if hasThreeSimilarDigits(i):
            file.write(str(i) + '\n')


def readAB(file):
    a, b = map(int, file.read().split())
    return a, b


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        left, right = readAB(inFile)
        printNum(left, right, outFile)
    inFile.close()
    outFile.close()


main()
