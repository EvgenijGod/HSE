def move(n, x, y, file):
    if n != 0:
        if n == 1 and y == 2:
            file.write('1 ' + str(x) + ' ' + str(6 - x - y) + '\n')
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
