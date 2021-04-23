#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    vector<int> numbers;
    int num;
    while (cin >> num)
        numbers.push_back(num);
    for (int el : numbers)
        cout << el << " ";
    cout << endl;
    set<int> occurrences;
    for (int el : numbers) {
        if (occurrences.find(el) != occurrences.end()) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
            occurrences.insert(el);
        }
    }
    return 0;
}

