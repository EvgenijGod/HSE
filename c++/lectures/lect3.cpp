***************************************************************
		LECTURE 3. TUPLE, PAIRS, FUNCTIONS

#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> v;
  for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it << " ";
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    cout << *it << " ";
}


*****************************************************

#include <iostream>
#include <tuple>
#include <string>
#include <utility>

using namespace std;

int main() {
  pair<int, double> p;
  //pair p{42, 3.14};
  p.first = 42;
  p.second = 3.14;
  auto [x, y] = p; // x = p.first; y = p.second;


  tuple<int, double, string> t = {1, 2.3, "hello"};
  get<0>(t) = get<1>(t); //get<0> == 2;
  cout << get<0>(t) << " ";
  cout << get<1>(t) << " ";
  cout << get<2>(t) << " ";
  auto [a, b, c] = t;

}


***********************************************

functions

int sum(int a, int b) {
  return a + b;
}

int fact(int n) {
  if (n == 0)
    return 1;
  return n * fact(n - 1);
}

bool is_palindrome(const string& s) {
  for (size_t i = 0; i != s.size() / 2; ++i) {
    if (s[i] != s[s.size() - i - 1])
      return false;
  }
  return true;
}

string sum(const string& a, const string& b) {
  return a + b;
}

pair<int, int> minmax(const vector<int>& v) {
  return {0, 0};
}

int main() {
  int x, y;
  cin >> x >> y;
  cout << sum(x, y) << "\n";
  cout << fact(5) << "\n";
  string phrase;
  getline(cin, phrase);
  cout << is_palindrome(phrase) << "\n";
}

**********************************************

#include <iostream>

using namespace std;

void swap(int& x, int& y) { // incorrect: (int x, int y)
  int c = x;
  x = y;
  y = c;
}

int main() {
  int x = 1;
  int y = 2;
  swap(x, y);
  cout << x << " " << y; // incorrect: 1, 2
  swap(1, 2); // нельзя
  
}


