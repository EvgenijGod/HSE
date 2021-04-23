numList = list(map(int, input().split()))
seqMax = numList[0]
maxIndex = 0
for i in range(len(numList)):
    if numList[i] > seqMax:
        seqMax = numList[i]
        maxIndex = i
print(seqMax, maxIndex)
