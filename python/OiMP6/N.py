numList = list(map(int, input().split()))
for i in range(0, len(numList) - 1, 2):
    numList[i], numList[i + 1] = numList[i + 1], numList[i]
for i in range(len(numList)):
    print(numList[i])
