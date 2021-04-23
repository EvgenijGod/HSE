def readList(file):
    listLen = int(file.readline())
    resList = []
    for i in range(listLen):
        resList.append(file.readline())
    return resList


def readDict(file):
    dictLen = int(file.readline())
    langDict = {}
    for i in range(dictLen):
        lang = file.readline().strip()
        alphabet = file.readline().strip()
        langDict[lang] = alphabet
    return langDict


def checkAlphabet(word, langDict):
    correctLanguage = set()
    for char in word:
        for language in langDict:
            if char in langDict[language]:
                correctLanguage.add(language)
    return sorted(correctLanguage)


def listAlphabet(langDict, wrdsList, file):
    for word in wrdsList:
        resSet = checkAlphabet(word, langDict)
        for el in resSet:
            file.write(str(el) + ' ')
        file.write('\n')


def main():
    with open('input.txt', 'r') as inFile, open('output.txt', 'w') as outFile:
        pass
        lngDict = readDict(inFile)
        listWrds = readList(inFile)
        listAlphabet(lngDict, listWrds, outFile)
    inFile.close()
    outFile.close()


main()
