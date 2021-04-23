def main():
    digitList = [0, 0, 0, 0, 0, 0, 0, 0, 0]
    currentNum = int(input())
    while currentNum:
        digitList[currentNum - 1] += 1
        currentNum = int(input())
    print(*digitList)


main()
