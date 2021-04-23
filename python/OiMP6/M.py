numList = list(map(int, input().split()))
length = len(numList)
for i in range(length // 2):
    numList[i], numList[length - i - 1] = numList[length - i - 1], numList[i]
for i in range(length):
    print(numList[i])
