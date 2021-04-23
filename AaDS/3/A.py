def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def keyIsBroken(n, keys, keysPressed, file):
    for i in range(n):
        if keysPressed.count(i + 1) > keys[i]:
            file.write('yes\n')
        else:
            file.write('no\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, keyAbility = readArray(inFile)
        m, keysPressed = readArray(inFile)
        keyIsBroken(n, keyAbility, keysPressed, outFile)
    inFile.close()
    outFile.close()


main()
