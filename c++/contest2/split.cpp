#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> split(const std::string& str, char delimiter) {
    std::vector<std::string> split_strings;
    if (str.find(delimiter) == std::string::npos) {
        split_strings = {str};
        return split_strings;
    }
    size_t pos = 0;
    while (str.find(delimiter, pos) != std::string::npos) {
        std::string word;
        word = str.substr(pos, str.find(delimiter, pos) - pos);
        split_strings.push_back(word);
        pos = str.find(delimiter, pos) + 1;
    }
    split_strings.push_back(str.substr(pos));
    return split_strings;
}

int main() {
    std::string phrase;
    getline(std::cin, phrase);
    char del;
    std::cin >> del;
    std::vector<std::string> s = split(phrase, del);
    for (std::string d:s)
        std::cout << d << "\n";
    return 0;
}

