def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def clothes(sh, n, pnts, m):
    i = 0
    j = 0
    while i == 0 or j == 0:
        if i >= n:
            j += 1
        elif j >= m:
            i += 1
        elif sh[i] == pnts[j]:
            i += 1
            j += 1
        elif sh[i] < pnts[j]:
            i += 1
        elif pnts[j] < sh[i]:
            j += 1
    return sh[i - 1], pnts[j - 1]


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, shirts = readArray(inFile)
        m, pants = readArray(inFile)
        sh, p = clothes(shirts, n, pants, m)
        outFile.write(str(sh) + ' ' + str(p))
    inFile.close()
    outFile.close()


##main()
a = [1, 2, 3]
b = a + [4]
print(b, a)