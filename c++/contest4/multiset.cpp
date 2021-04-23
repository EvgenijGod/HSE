#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    size_t n, k;
    cin >> n >> k;
    vector<int> numbers(n);
    for (size_t i = 0; i != n; ++i)
        cin >> numbers[i];
    for (size_t i = 0; i != n - k + 1; ++i) {
        multiset<int> m_set;
        for (size_t j = 0; j != k; ++j) {
            m_set.insert(numbers[i + j]);
        }
        cout << *m_set.begin() << "\n";
    }
    return 0;
}

