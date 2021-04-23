#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> readLines() {
    string in_word;
    vector<string> text;
    while (cin >> in_word)
        text.push_back(in_word);
    return text;
}

int main() {
    vector<string> text = readLines();
    map<char, int> freq;
    set<char> letters;
    size_t max_freq = 0;
    for (const string &word : text) {
        for (const char &symb : word)
            if (symb != ' ' && symb != '\n') {
                ++freq[symb];
                letters.insert(symb);
                if (freq[symb] > max_freq)
                    max_freq = freq[symb];
            }
    }
    for (size_t i = max_freq; i != 0; --i) {
        for (const char &letter : letters) {
            if (freq[letter] >= i)
                cout << "#";
            else
                cout << " ";
        }
        cout << "\n";
    }
    for (const char &letter : letters)
        cout << letter;
    cout << "\n";
}

