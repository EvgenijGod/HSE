kmsPerDay = int(input())
hwLen = int(input())
tail = hwLen % kmsPerDay
print(hwLen // kmsPerDay + (tail + kmsPerDay - 1) // kmsPerDay)
