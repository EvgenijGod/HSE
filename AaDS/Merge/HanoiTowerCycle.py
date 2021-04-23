def move(n, x, y, file):
    if n != 0:
        if (x == 1 and y == 2) or (x == 2 and y == 3) or (x == 3 and y == 1):
            move(n - 1, x, 6 - x - y, file)
            file.write(str(n) + ' ' + str(x) + ' ' + str(y) + '\n')
            move(n - 1, 6 - x - y, y, file)
        else:
            move(n - 1, x, y, file)
            file.write(str(n) + ' ' + str(x) + ' ' + str(6 - x - y) + '\n')
            move(n - 1, y, x, file)
            file.write(str(n) + ' ' + str(6 - x - y) + ' ' + str(y) + '\n')
            move(n - 1, x, y, file)


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n = int(inFile.readline())
        move(n, 1, 3, outFile)
    inFile.close()
    outFile.close()


main()
