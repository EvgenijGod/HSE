import sys


def trafficLight(greenLight):
    redLight = greenLight
    yellowLight = 1 + 2 * (greenLight - 1)
    return redLight, yellowLight


def main():
    grLight = int(sys.stdin.readline())
    print(*trafficLight(grLight))


main()
