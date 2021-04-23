#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  getline(cin, s);
  int i = 0;
  int j = s.length() - 1;
  while (i < j) {
    while (s[i] == ' ')
      ++i;
    while (s[j] == ' ')
      --j;
    if (s[i] != s[j]) {
      cout << "no\n";
      return 0;
    } else {
      ++i;
      --j;
    }
  }
  cout << "yes\n";
  return 0;
}

