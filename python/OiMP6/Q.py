numList = list(map(int, input().split()))
delIndex = int(input())
for i in range(delIndex, len(numList) - 1):
    numList[i] = numList[i + 1]
numList.pop()
for i in range(len(numList)):
    print(numList[i])
