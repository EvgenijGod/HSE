n = int(input())  # 4 digits
leftNumber = n // 100
rightNumber = n % 100
leftNumber = leftNumber % 10 * 10 + leftNumber // 10
print(leftNumber - rightNumber + 1)
