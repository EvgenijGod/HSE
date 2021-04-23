def AddToSum(a, sumSeq):
    if a == 0:
        return sumSeq
    else:
        return a + AddToSum(int(input()), sumSeq)


sumSeq = 0
a = int(input())
print(AddToSum(a, sumSeq))
