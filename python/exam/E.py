def readList(file):
    return list(map(int, file.readline().split()))


def printList(resList, file):
    for el in resList:
        file.write(str(el) + '\n')


def sortB(line):
    i = 0
    while line[i] == ' ':
        i += 1
    return line[i:]


def sortF(line):
    return line.lower()


def sortR(line):



def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        pass
        print(sortR('   12 aBc'))
    inFile.close()
    outFile.close()


main()
