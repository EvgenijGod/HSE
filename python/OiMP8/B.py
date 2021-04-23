newList = list(map(int, input().split()))
maxElmnt = newList[0]
maxIndx = 0
for i in range(len(newList)):
    if newList[i] >= maxElmnt:
        maxElmnt = newList[i]
        maxIndx = i
print(maxElmnt, maxIndx)
