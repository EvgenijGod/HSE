def sumFact(n):
    sumF = 0
    curFact = 1
    for i in range(1, n + 1):
        sumF += i * curFact
        curFact *= i
    return sumF


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        res = sumFact(int(inFile.readline()))
        outFile.write(str(res))
    inFile.close()
    outFile.close()


main()
