#include <iostream>
#include <vector>

void swap_columns(std::vector<std::vector<int> >& matrix, size_t i, size_t j) {
  for (int k = 0; k != matrix.size(); ++k)
    swap(matrix[k][i], matrix[k][j]);
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  std::vector<vector<int> > v;
  v.resize(n);
  for (int ii = 0; ii != n; ++ii) {
    v[ii].resize(m);
    for (int jj = 0; jj != m; ++jj)
      std::cin >> v[ii][jj];
  }
  size_t i, j;
  std::cin >> i >> j;
  swap_columns(v, i, j);
  for (size_t ii = 0; ii != n; ++ii) {
    for (size_t jj = 0; jj != m; ++jj)
      std::cout << v[ii][jj] << " ";
    std::cout << "\n";
  }
  return 0;
}

