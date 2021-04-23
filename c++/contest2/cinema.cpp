#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<string> seats (n);
  for (size_t i = 0; i != n; ++i) {
    string row;
    for (size_t j = 0; j != m; ++j) {
      int seat;
      cin >> seat;
      row += to_string(seat);
    }
    seats[i] = row;
  }
  int k;
  cin >> k;
  string seats_to_book;
  for (size_t i = 0; i != k; ++i)
    seats_to_book += '0';
  for(size_t i = 0; i != n; ++i) {
    if (seats[i].find(seats_to_book) != string::npos) {
      cout << i + 1 << "\n";
      return 0;
    }
  }
  cout << 0 << "\n";
  return 0;
}

