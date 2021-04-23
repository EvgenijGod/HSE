def move(n, x, y, file):
    if n != 0:
        z = 3 - n % 2
        move(n - 1, x, 6 - x - z, file)
        if x != z:
            file.write(str(n) + ' ' + str(x) + ' ' + str(z) + '\n')
        move(n - 1, 6 - x - z, y, file)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n = int(inFile.readline())
        move(n, 1, 3 - n % 2, outFile)
    inFile.close()
    outFile.close()


main()
