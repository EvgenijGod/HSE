numList = list(map(int, input().split()))
oddMin = 0
for i in range(len(numList)):
    if oddMin == 0 and numList[i] % 2 != 0:
        oddMin = numList[i]
    else:
        if numList[i] % 2 != 0 and numList[i] < oddMin:
            oddMin = numList[i]
print(oddMin)
