p = int(input())
x = int(input())
y = int(input())
k = int(input())
cnt = 1
interestRate = 100 + p
while cnt <= k:
    origSum = x * 100 + y
    yearSum = interestRate * origSum
    x = int(yearSum // 10000)
    y = int((yearSum % 10000) // 100)
    cnt += 1
print(x, y)
