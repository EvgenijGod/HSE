numList = list(map(int, input().split()))
cntLocalMax = 0
for i in range(1, len(numList) - 1):
    if numList[i - 1] < numList[i] and numList[i] > numList[i + 1]:
        cntLocalMax += 1
print(cntLocalMax)
