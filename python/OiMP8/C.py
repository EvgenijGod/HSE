n = int(input())
newList = list(map(int, input().split()))
x = int(input())
closestElement = newList[0]
minDelta = abs(closestElement - x)
for i in range(n):
    if abs(newList[i] - x) < minDelta:
        minDelta = abs(newList[i] - x)
        closestElement = newList[i]
print(closestElement)
