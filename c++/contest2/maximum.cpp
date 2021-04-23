#include <iostream>
#include <vector>

//using namespace std;

std::pair<size_t, size_t> max_element(const std::vector<std::vector<int> >& matrix) {
  int max_el = matrix[0][0];
  std::pair<size_t, size_t> max_el_it;
  for (size_t i = 0; i != matrix.size(); ++i)
    for (size_t j = 0; j != matrix[i].size(); ++j)
      if (matrix[i][j] > max_el) {
        max_el = matrix[i][j];
        max_el_it.first = i;
        max_el_it.second = j;
      }
  return max_el_it;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int> > matrix;
  matrix.resize(n);
  for (size_t i = 0; i != n; ++i) {
    matrix[i].resize(m);
    for (size_t j = 0; j != m; ++j)
      std::cin >> matrix[i][j];
  }
  size_t i, j;
  i = max_element(matrix).first;
  j = max_element(matrix).second;
  std::cout << i << " " << j;
  return 0;
}

