line = str(input())
firstIn = line.find('h')
lastIn = line.rfind('h')
reversedFragment = line[lastIn:firstIn:-1]
line = line[:firstIn] + reversedFragment + line[lastIn:]
print(line)
