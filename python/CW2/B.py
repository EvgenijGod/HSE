def seqGen(n, k):
    for i in range(1, k + 1):
        for t in range(1, k + 1):
                print(j, t, sep=' ')


def main():
    n, k = map(int, input().split())
    seqGen(n, k)

main()
