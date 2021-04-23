#include <iostream>
#include <vector>

//using namespace std;
std::string common_prefix(const std::vector<std::string>& words) {
    std::string common;
    size_t min_size = words[0].size();
    for (std::string word : words) {
        if (word.length() < min_size)
            min_size = word.length();
    }
    for (size_t i = 0; i != min_size; ++i) {
        char current_symb = words[0][i];
        for (size_t j = 0; j != words.size(); ++j)
            if (words[j][i] != current_symb)
                return common;
        common += current_symb;
    }
    return common;
}

int main() {
    std::vector<std::string> w = {"ab", "abc"};
    std::cout << w[0].size();
    std::cout << common_prefix(w);
}
