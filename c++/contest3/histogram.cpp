#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> readLines() {
    string in_word;
    vector<string> text;
    while (getline(cin, in_word))
        text.push_back(in_word);
    return text;
}

int main() {
    vector<string> text = readLines();
    set<char> letters_in_text;
    map<char, size_t> freqs;
    size_t max_freq = 0;
    for (const string &word : text) {
        for (char letter : word) {
            if (letter != ' ' && letter != '\n') {
                ++freqs[letter];
                if (freqs[letter] > max_freq)
                    max_freq = freqs[letter];
                letters_in_text.insert(letter);
            }
        }
    }
    for (size_t i = max_freq; i != 0; --i) {
        for (char letter : letters_in_text) {
            if (freqs[letter] >= i)
                cout << '#';
            else
                cout << ' ';
        }
        cout << '\n';
    }
    for (char letter : letters_in_text)
        cout << letter;
    cout << "\n";
    return 0;
}

