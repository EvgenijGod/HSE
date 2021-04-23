#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> perm1;
  perm1.reserve(n);
  for (size_t i = 0; i != n; ++i) {
    int x;
    cin >> x;
    perm1.push_back(x);
  }
  vector<int> perm2;
  perm2.resize(n);
  for (size_t i = 0; i != n; ++i)
    perm2[perm1[i] - 1] = i + 1;
  for (size_t i = 0; i != perm2.size(); ++i)
    cout << perm2[i] << " ";
  cout << "\n";
  return 0;
}

