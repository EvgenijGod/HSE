#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> readLines() {
    string word_in;
    vector<string> words;
    while (getline(cin, word_in)) {
        if (word_in != "\n")
            words.push_back(word_in);
    }
    return words;
}

int main() {
    string code;
    cin >> code;
    vector<string> words;
    words = readLines();
    if (code == "ASCENDING") {
        sort(words.begin(),
             words.end(),
             [](const string &word1, const string &word2) {
                 return word1 < word2;
             });
    } else if (code == "DESCENDING") {
        sort(words.begin(),
             words.end(),
             [](const string &word1, const string &word2) {
                 return word1 > word2;
             });
    }
    for (const string &word : words) {
        if (word != "\n" && !word.empty())
            cout << word << "\n";
    }
    return 0;
}

