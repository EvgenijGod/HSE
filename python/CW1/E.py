n = int(input())
sumDigits = 0
while n > 0:
    sumDigits += n % 10
    n //= 10
print(sumDigits)
