#include <iostream>
#include <vector>

void reverse(std::vector<int>& numbers) {
  for (size_t i = 0; i != numbers.size() / 2; ++i)
    std::swap(numbers[i], numbers[numbers.size() - i - 1]);
}

int main() {
  std::vector<int> v;
  size_t n;
  std::cin >> n;
  v.resize(n);
  for(size_t i = 0; i != n; ++i)
    std::cin >> v[i];
  reverse(v);
  for(size_t i = 0; i != n; ++i)
    std::cout << v[i];
  return 0;
}

