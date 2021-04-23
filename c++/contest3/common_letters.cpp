#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

int main() {
    vector<string> words;
    string in_word;
    while (getline(cin, in_word))
        words.push_back(in_word);
    set<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                          'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (const string& word : words) {
        for (char letter : alphabet) {
            if (word.find(letter) == string::npos)
                alphabet.erase(letter);
        }
    }
    for (char letter : alphabet) {
        cout << letter;
    }
    cout << "\n";
}
