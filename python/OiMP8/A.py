newList = list(map(int, input().split()))


def IsAscending(A):
    indNow = 0
    while indNow < len(A) - 1 and A[indNow] < A[indNow + 1]:
        indNow += 1
    return indNow


if IsAscending(newList) == len(newList) - 1:
    print('YES')
else:
    print('NO')
