def soundex(word):
    tmpResult = word[0]
    for i in range(1, len(word)):
        if word[i] in 'aehiouwy':
            continue
        if word[i] in 'bfpv':
            tmpResult += '1'
        if word[i] in 'cgjkqsxz':
            tmpResult += '2'
        if word[i] in 'dt':
            tmpResult += '3'
        if word[i] == 'l':
            tmpResult += '4'
        if word[i] in 'mn':
            tmpResult += '5'
        if word[i] == 'r':
            tmpResult += '6'
    result = word[0]
    i = 1
    while i < len(tmpResult):
        currentChar = tmpResult[i]
        result += currentChar
        while i < len(tmpResult) and tmpResult[i] == currentChar:
            i += 1
    result += '0000'
    return result[:4]


def main():
    print(soundex(input()))


main()
