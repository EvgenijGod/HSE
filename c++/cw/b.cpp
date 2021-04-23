#include <cctype>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_palindrome(const string& s) {
    for (size_t i = 0; i != s.size() / 2; ++i)
        if (s[i] != s[s.size() - i - 1])
            return false;
    return true;
}

int main() {
    string line;
    getline(cin, line);
    string newline;
    for (char c : line) {
        if (isalpha(c)) {
            if (isupper(c))
                newline += tolower(c);
            else
                newline += c;
	}
    }
    if (is_palindrome(newline))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
