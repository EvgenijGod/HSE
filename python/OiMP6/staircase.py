numList = list(map(int, input().split()))
positiveMin = 1001
for i in range(len(numList)):
    if numList[i] > 0 and numList[i] < positiveMin:
        positiveMin = numList[i]
print(positiveMin)
