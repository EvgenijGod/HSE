**********************************************************

                  СЕМИНАР 2 (17.01.2019)

**********************************************************

/*
s.size() returns value of type size_t
type size_t [0, 2^64 - 1)
stoi("   1234abc") -> stoi("1234") = 1234;
[..;   a0;a1;........;a{n-1};...]
rend()                      end()
      begin()         rbegin()
iterators ~ это класс (суперкласс (нет))
в векторе прибавление к итератору i - шагаем вперёд на i
*/

**********************************************************

использование using и typedef

using kilograms = double;
using cubicMeters = double;

struct Box {
  kilograms weight;
  cubicMeters volume;
}

cubicMeters shrink_volume_of_object(cubicMeters volume) {
  return 0.5 * volume;
}

**********************************************************

ФИКСИРОВАННЫЕ ТИПЫ

uint64_t fixed_width_a; //типы фиксированной ширины

**********************************************************

#include <iostream>
#include <iterator>
#include <vector>

void print_vector(const vector<int> &v) {
  for (size_t j = 0; j < v.size(); ++j) {
    cout << v[j] << " ";
  }
  cout << endl;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> v(n);
  for (size_t j = 0; j < n; ++j)
    cin >> v[j];
  vector<int>::iterator it_start = v.begin();
  vector<int>::iterator it_finish = --v.end();
  for (;it_start < it_finish; ++it_start, --it_finish) {
    swap(*it_start, *it_finish);
  }
  print_vector(v);  //reverse using iterators
}

************************************************************

#include <iostream>
#include <iterator>
#include <vector>

void print_vector(const vector<int> &v) {
  for (size_t j = 0; j < v.size(); ++j) {
    cout << v[j] << " ";
  }
  cout << endl;
}

bool my_comp (int a, int b) {
  return a % 10 < b % 10;
}

int main() {
  size_t n;
  cin >> n;
  vector<int> v(n);
  for (size_t j = 0; j < n; ++j)
    cin >> v[j];
  sort(v.begin(), v.end());
  print_vector(v);  // sort
  sort(v.rbegin(), v.rend());
  print_vector(v);  // sort in reserve
  sort(v.begin(), v.end(), greater<int>()); // comparators
  print_vector(v);  // sort in reverse
  sort(v.begin(), v.end(), my_comp);
  print_vector(v);  // sort by mod 10
}

************************************************************
