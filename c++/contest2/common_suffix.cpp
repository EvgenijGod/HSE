#include <iostream>
#include <string>

std::string common_suffix(const std::string& a, const std::string& b) {
    size_t i = a.length() - 1;
    size_t j = b.length() - 1;
    std::string common_part;
    while (i != -1 && j != -1 && a[i] == b[j]) {
        common_part += a[i];
        --i;
        --j;
    }
    for (size_t k = 0; k != common_part.size() / 2; ++k)
        std::swap(common_part[k], common_part[common_part.size() - k - 1]);
    return common_part;
}

int main() {
    std::string a, b;
    getline(std::cin, a);
    getline(std::cin, b);
    std::cout << common_suffix(a, b) << "\n";
    return 0;
}

