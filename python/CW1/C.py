a = int(input())
b = int(input())
c = int(input())
if a > b:
    if a > c:
        if a < b + c:
            print('YES')
        else:
            print('NO')
    else:
        if c < a + b:
            print('YES')
        else:
            print('NO')
elif c > b:
    if c < b + a:
        print('YES')
    else:
        print('NO')
elif b < c + a:
    print('YES')
else:
    print('NO')
