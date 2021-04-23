def readList(file):
    strings = []
    mas = list(file.read().split())
    return mas


def main():
    in_file = open('input.txt', 'r')
    out_file = open('output.txt', 'w')
    mas = readList(in_file)
    print(*mas)


main()
