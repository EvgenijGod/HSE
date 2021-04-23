h = int(input())
m = int(input())
s = int(input())
timeSec = h * 3600 + m * 60 + s
timeSec %= 12 * 60 * 60
deltaAngle = timeSec * (360 / (12 * 60 * 60))
if deltaAngle == int(deltaAngle):
    print(int(deltaAngle))
else:
    print(deltaAngle)
