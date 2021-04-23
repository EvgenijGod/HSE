numList = list(map(int, input().split()))
k, c = map(int, input().split())
lastElement = numList[len(numList) - 1]
for i in range(len(numList) - 1, k, -1):
    numList[i] = numList[i - 1]
numList[k] = c
numList.append(lastElement)
for i in range(len(numList)):
    print(numList[i])
