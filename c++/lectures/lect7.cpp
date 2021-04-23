#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using Iterator = std::vector<int>::iterator;

void PrintVector(const std::vector<int>& v) {
    std::cout << "data: ";
    for (const auto x: v) {
        std::cout << x << ' ';
    }
    std::cout << '\n';
}


void WriteZero(Iterator it) {
    *it = 0;
}


void WriteZero(Iterator first, Iterator last) {
    while (first != last) {
        *first = 0;
        ++first;
        // the same as two lines above
        // *first++ = 0;
    }
}

// src ~ source, dst ~ destination
void Write(Iterator src, Iterator dst_first, Iterator dst_last) {
    while (dst_first != dst_last) {
        *dst_first++ = *src;
    }
}

// *src from dst_first to dst_last)

void Copy(Iterator src_first, Iterator src_last, Iterator dst_first) {
    while (src_first != src_last) {
        *dst_first = *src_first;
        ++src_first;
        ++dst_first;
    }
}

int main() {
    vector<int> vec = {100, 200, 300};
    auto it = vec.begin();
    cout << *next(it) << "\n";
    advance(it, 2); // changes iterator
    cout << *it << "\n";
    cout << distance(vec.begin(), it) << "\n";
    return 0;
}

***********************************************************************************

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <typename T>
T Min(const T& first, const T& second) {
    return first < second ? first : second;
}

template <typename T>
T Read() {
    T value;
    cin >> value;
    return value;
}

template <typename F>
bool Apply(F func, int value) {
    return func(value);
}

int main() {
    const auto n = Read<int>();
    const auto s = Read<string>();
    cout << boolalpha << Min(n, n + 1) << "\n" << Min(s, s + "hello") << "\n";
    return 0;
}

