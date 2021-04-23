import math


def squareSize(w, h, n):
    size1 = math.floor((w * h * n) ** 0.5)
    size2 = math.ceil((w * h * n) ** 0.5)
    if (size1 // w) * (size1 // h) >= n:
        return size1
    elif (size2 // w) * (size2 // h) >= n:
        return size2
    else:
        return size2 + 1


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        w, h, n = map(int, inFile.readline().split())
        outFile.write(str(squareSize(w, h, n)))
    inFile.close()
    outFile.close()


main()
