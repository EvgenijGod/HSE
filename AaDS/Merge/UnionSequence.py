import sys


def seqEl(x):
    i = 1
    j = 1
    el = 0
    for cnt in range(x):
        if i ** 2 < j ** 3:
            el = i ** 2
            i += 1
        elif j ** 3 < i ** 2:
            el = j ** 3
            j += 1
        else:
            el = i ** 2
            i += 1
            j += 1
    return el


def main():
    print(seqEl(int(sys.stdin.readline())))


main()
