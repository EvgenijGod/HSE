def readArray(file):
    n = int(file.readline())
    arr = list(map(int, file.readline().split()))
    return n, arr


def findMin(arr, l, r):
    m = (l + r) // 2
    print('el:')
    print(arr[m], arr[l], arr[r])
    if r - l >= 2:
        if arr[m] < arr[m + 1] and arr[m] < arr[m - 1]:
            print('done')
            return arr[m]
        elif arr[m] > arr[r]:
            print('right')
            return findMin(arr, m + 1, r)
        elif arr[m] < arr[r]:
            print('left')
            return findMin(arr, l, m - 1)

    else:
        return min(arr[l], arr[r])


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        n, arr = readArray(inFile)
        print(findMin(arr, 0, n - 1))
    inFile.close()
    outFile.close()


main()
