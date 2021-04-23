#include <iostream>
#include <vector>

std::vector<std::vector<int> > transpose(const std::vector<std::vector<int> >& matrix) {
  std::vector<std::vector<int> > tr_matrix;
  tr_matrix.resize(matrix[0].size());
  for (size_t i = 0; i != matrix[0].size(); ++i) {
    tr_matrix[i].resize(matrix.size());
    for (size_t j = 0; j != matrix.size(); ++j)
      tr_matrix[i][j] = matrix[j][i];
  }
  return tr_matrix;
}

int main() {
  std::vector<std::vector<int> > v;
  size_t n, m;
  std::cin >> n >> m;
  v.resize(n);
  for (size_t i = 0; i != n; ++i) {
    v[i].resize(m);
    for (size_t j = 0; j != m; ++j)
      std::cin >> v[i][j];
  }
  std::vector<std::vector<int> > res = transpose(v);
  for (size_t i = 0; i != m; ++i) {
    for (size_t j = 0; j != n; ++j)
      std::cout << res[i][j] << " ";
    std::cout << "\n";
  }
  return 0;
}

