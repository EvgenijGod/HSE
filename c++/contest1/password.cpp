#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int main() {
  string pass;
  getline(cin, pass);
  if (pass.length() > 14 || pass.length() < 8) {
    cout << "NO\n";
    return 0;
  }
  bool lwrcs = false;
  bool upprcs = false;
  bool digit = false;
  bool other = false;
  for (char c : pass) {
    if (static_cast<int>(c) > 127 || static_cast<int>(c) < 33) {
      cout << "NO\n";
      return 0;
    }
    if (islower(c))
      lwrcs = true;
    else if (isupper(c))
      upprcs = true;
    else if (isdigit(c))
      digit = true;
    else
      other = true;
  }
  if (lwrcs + upprcs + digit + other > 2)
    cout << "YES\n";
  else
    cout << "NO\n";
  return 0;
}

