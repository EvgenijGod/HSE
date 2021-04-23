#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  double sum = 0;
  double sgn = 1.0;
  for (int i = 1; i <= n; ++i) {
     sum += sgn / i;
     sgn *= -1;
  }
  cout << sum << "\n";
  return 0;
}

