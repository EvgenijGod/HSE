def readVotes(file):
    return list(map(int, file.readline().split()))


def election(x, y, z):
    if x == y or x == z:
        return x
    else:
        return y


def main():
    with open('input.txt', 'w') as inFile, open('output.txt', 'w') as outFile:
        votes = readVotes(inFile)
        x = votes[0]
        y = votes[1]
        z = votes[2]
        outFile.write(str(election(x, y, z)))
    inFile.close()
    outFile.close()


main()
