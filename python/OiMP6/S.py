numList = list(map(int, input().split()))
cntPairs = 0
for i in range(len(numList)):
    for j in range(i + 1, len(numList)):
        if numList[j] == numList[i]:
            cntPairs += 1
print(cntPairs)
