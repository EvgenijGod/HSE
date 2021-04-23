n = int(input())
lessonMin = 45 * n
breakMin = (n // 2) * 5 + (n - 1) // 2 * 15
timeMin = lessonMin + breakMin + 9 * 60
print(timeMin // 60, timeMin % 60)
