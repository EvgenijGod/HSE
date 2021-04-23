n = int(input())  # seconds from 00:00
n %= 24 * 60 * 60
seconds = n % 60
hours = n // 3600
minutes = n // 60 - hours * 60
print(hours, end=':')
print(minutes // 10, minutes % 10, sep='', end=':')
print(seconds // 10, seconds % 10, sep='')
