price = float(input())
rubles = int(price)
kopeck = int(price * 100) % 100
print(rubles, kopeck)
