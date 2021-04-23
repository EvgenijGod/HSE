correctAns = int(input())
studentAns = int(input())
if correctAns == 1:
    if studentAns == 1:
        print('YES')
    else:
        print('NO')
elif studentAns != 1:
    print('YES')
else:
    print('NO')
