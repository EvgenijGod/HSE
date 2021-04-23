numList = list(map(int, input().split()))
heightPetya = int(input())


def PlaceInLine(heightLine, height):
    for i in range(len(heightLine)):
        if heightLine[i] < height:
            return i + 1
    return len(heightLine) + 1


print(PlaceInLine(numList, heightPetya))
