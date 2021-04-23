n = int(input())  # size
m = int(input())  # size
k = int(input())  # needed amount
if k < n * m and (k % n == 0 or k % m == 0):
    print('YES')
else:
    print('NO')
