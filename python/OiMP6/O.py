numList = list(map(int, input().split()))
lastElement = numList[len(numList) - 1]
for i in range(len(numList) - 1, 0, -1):
    numList[i] = numList[i - 1]
numList[0] = lastElement
for i in range(len(numList)):
    print(numList[i])
