x = int(input())  # first flat
y = int(input())  # last flat
if (x - 1) % (y - x + 1) == 0:
    print('YES')
else:
    print('NO')
