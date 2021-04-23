import sys


def readArr(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def maxSaw(arr, n):
    maxLen = 1
    for i in range(2, n + 1):
        subSeq = []



def main():
    n, arr = readArr(sys.stdin)
    print(maxSaw(arr, n))


main()
