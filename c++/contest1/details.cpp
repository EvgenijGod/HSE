#include <iostream>

using namespace std;

int main() {
  int n, k, m;
  cin >> n >> k >> m;
  int rmn, dtls = 0;
  rmn = n % k;
  while (n >= k && k >= m) {
    int barCnt = n / k;
    dtls += barCnt * (k / m);
    rmn += (barCnt * (k % m));
    n = rmn;
    rmn = n % k;
  };
  cout << dtls << "\n";
  return 0;
}

