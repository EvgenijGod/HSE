import sys


def readArray(file):
    return list(map(int, file.readline().split()))


def median(arr1, arr2, l):
    i = 0
    j = 0
    while (i + j) < l - 1:
        if i < l and arr1[i] < arr2[j]:
            i += 1
        elif j < l:
            j += 1
    if arr1[i] < arr2[j]:
        return arr1[i]
    else:
        return arr2[j]


def medians(sequences, n, l):
    for i in range(n):
        for j in range(i + 1, n):
            print(median(sequences[i], sequences[j], l))


def main():
    n, l = map(int, sys.stdin.readline().split())
    sequences = []
    for i in range(n):
        arr = readArray(sys.stdin)
        sequences.append(arr)
    medians(sequences, n, l)


main()
