nowColumn = int(input())
previousColumn = nowColumn
peakCnt = 0
prevLower = False
while nowColumn != 0:
    nowColumn = int(input())
    if nowColumn != 0:
        if previousColumn > nowColumn and prevLower:
            peakCnt += 1
        if previousColumn < nowColumn:
            prevLower = True
        else:
            prevLower = False
    previousColumn = nowColumn
print(peakCnt)
