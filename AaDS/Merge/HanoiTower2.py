def move(n, x, y, file):
    if n != 0:
        if x + y == 4:
            move(n, x, 2, file)
            move(n, 2, y, file)
        else:
            move(n - 1, x, 6 - x - y, file)
            file.write(str(n) + ' ' + str(x) + ' ' + str(y) + '\n')
            move(n - 1, 6 - x - y, y, file)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n = int(inFile.readline())
        move(n, 1, 3, outFile)
    inFile.close()
    outFile.close()


main()
