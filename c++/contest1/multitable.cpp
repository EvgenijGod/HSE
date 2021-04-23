#include <iostream>

using namespace std;

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; ++i)
    cout << "\t" << i + 1;
  cout << "\n";
  for (int i = 1; i < n + 1; ++i) {
    cout << i;
    for (int j = 1; j < n + 1; ++j)
      cout << "\t" << (j * i) % m;
    cout << "\n";
  }
  return 0;
}

