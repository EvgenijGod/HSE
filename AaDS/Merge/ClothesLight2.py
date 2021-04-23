def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def clothes(sh, n, pnts, m):
    i = 0
    j = 0
    delta_min = 10000000
    i_sh = -1
    j_sh = -1
    sh_tmp = sh + [10000001]
    pnts_tmp = pnts + [10000001]
    while i < n or j < m:
        if sh_tmp[i] <= pnts_tmp[j]:
            i += 1
        elif pnts_tmp[j] < sh_tmp[i]:
            j += 1
        if i != 0 and j != 0:
            if abs(sh[i - 1] - pnts[j - 1]) < delta_min:
                delta_min = abs(sh[i - 1] - pnts[j - 1])
                i_sh = i - 1
                j_sh = j - 1
    return sh[i_sh], pnts[j_sh]


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, shirts = readArray(inFile)
        m, pants = readArray(inFile)
        sh, p = clothes(shirts, n, pants, m)
        outFile.write(str(sh) + ' ' + str(p))
    inFile.close()
    outFile.close()


main()
