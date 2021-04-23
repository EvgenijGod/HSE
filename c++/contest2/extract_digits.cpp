#include <cctype>
#include <iostream>
#include <string>

std::string ExtractDigits(const std::string& s) {
  std::string string_of_digits;
  for (char c : s)
    if (isdigit(c))
      string_of_digits += c;
  return string_of_digits;
}

int main() {
  std::string s;
  getline(std::cin, s);
  std::cout << ExtractDigits(s) << "\n";
  return 0;
}

