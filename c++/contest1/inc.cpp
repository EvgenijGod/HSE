#include <iostream>
#include <string>

using namespace std;

int main() {
  string s;
  cin >> s;
  int num[s.length() + 1];
  num[0] = 0;
  for (int i = 1; i < s.length() + 1; ++i)
    num[i] = s[i - 1] - '0';
  int dec;
  dec = (num[s.length()] + 1) / 10;
  num[s.length()] = (num[s.length()] + 1) % 10;
  int j = s.length() - 1;
  while (dec != 0) {
    dec = (num[j] + 1) / 10;
    num[j] = (num[j] + 1) % 10;
    --j;
  }
  if (num[0] != 0)
    cout << num[0];
  for (int i = 1; i < s.length() + 1; ++i)
    cout << num[i];
  cout << "\n";
  return 0;
}

