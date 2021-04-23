numList = list(map(int, input().split()))
cntDifferent = 1
for i in range(1, len(numList)):
    if numList[i] != numList[i - 1]:
        cntDifferent += 1
print(cntDifferent)
