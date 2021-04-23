newList = list(map(int, input().split()))
maxPositive1 = -1
maxPositive2 = -1
minNegative1 = 1
minNegative2 = 1
for i in range(len(newList)):
    if newList[i] >= 0:
        if newList[i] > maxPositive1:
            maxPositive2 = maxPositive1
            maxPositive1 = newList[i]
        elif newList[i] > maxPositive2:
            maxPositive2 = newList[i]
    elif newList[i] <= 0:
        if newList[i] < minNegative1:
            minNegative2 = minNegative1
            minNegative1 = newList[i]
        elif newList[i] < minNegative2:
            minNegative2 = newList[i]
if minNegative1 > 0 or minNegative2 > 0:
    print(maxPositive2, maxPositive1)
elif maxPositive2 < 0 or maxPositive1 < 0:
    print(minNegative1, minNegative2)
elif minNegative1 * minNegative2 > maxPositive1 * maxPositive2:
        print(minNegative1, minNegative2)
else:
    print(maxPositive2, maxPositive1)
