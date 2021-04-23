import sys


def readIntList(file):
    return list(map(int, file.readline().split()))


def hasPair(listCoord):
    for i in range(len(listCoord)):
        for j in range(i + 1, len(listCoord)):
            if abs(listCoord[0][i] - listCoord[0][j]) == abs(listCoord[1][i] - listCoord[1][j]):
                return True
    return False


def readCoord(file):
    resList = []
    for i in range(8):
        hor, vert = list(map(int, file.readline().split()))
        resList.append(newLine)
    return resList


def main():
    listCoord = readCoord(sys.stdin)
    if hasPair(listCoord):
        print('YES')
    else:
        print('NO')
