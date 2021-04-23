n = int(input())
sumSeq = 0
sumCards = 0
for i in range(n):
    sumCards += i + 1
for i in range(n - 1):
    nowCard = int(input())
    sumSeq += nowCard
print(sumCards - sumSeq)
