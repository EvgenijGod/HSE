#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> readLines() {
    string word_in;
    vector<string> words;
    while (cin >> word_in)
        words.push_back(word_in);
    return words;
}

int main() {
    size_t n;
    cin >> n;
    set<string> words;
    set<string> vocab;
    for (size_t i = 0; i != n; ++i) {
        string word_to_vocab;
        cin >> word_to_vocab;
        vocab.insert(word_to_vocab);
    }
    string word_in;
    vector<string> text;
    while (cin >> word_in)
        text.push_back(word_in);
    for (const string &word : text) {
        if (vocab.find(word) == vocab.end())
            words.insert(word);
    }
    for (const string &word : words)
        cout << word << "\n";
    return 0;
}

