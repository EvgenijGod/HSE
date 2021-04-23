numList = list(map(int, input().split()))
listMax = numList[0]
listMin = numList[0]
minIndex = 0
maxIndex = 0
for i in range(len(numList)):
    if numList[i] < listMin:
        listMin = numList[i]
        minIndex = i
    if numList[i] > listMax:
        listMax = numList[i]
        maxIndex = i
numList[minIndex], numList[maxIndex] = numList[maxIndex], numList[minIndex]
for i in range(len(numList)):
    print(numList[i])
