#include <iostream>
#include <string>
#include <vector>

std::string join(const std::vector<std::string>& tokens, char delimeter) {
    std::string joined_str;
    for (size_t i = 0; i != tokens.size(); ++i) {
        joined_str += tokens[i];
        if (i != tokens.size() - 1)
            joined_str += delimeter;
    }
    return joined_str;
}

int main() {
    size_t n;
    std::cin >> n;
    std::vector<std::string> v;
    v.resize(n);
    for (size_t i = 0; i != n; ++i)
        std::cin >> v[i];
    char del;
    std::cin >> del;
    std::cout << join(v, del);
}

