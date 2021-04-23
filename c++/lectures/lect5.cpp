#include <algorithm>
#include <array>
#include <iostream>
#include <set>
#include <deque> // double-ended queue
#include <list>
using namespace std;

int main() {
    deque<int> d = {3, 14,15};
    d.push_back(100500);
    d.push_front(13);
    for (size_t i = 0; i != d.size(); ++i)
        cout << d[i] << " ";
    cout << "\n";


    list<int> l = {3, 14, 15};
    auto it = find(l.begin(), l.end(), 14);
    l.insert(it, 42);
    l.erase(it);
    l.sort();
    for (auto x : l)
        cout << x << " ";
    cout << "\n";

    array<int, 5> a = {1, 2, 3, 4, 5};
    for (auto el : a)
        cout << el << " ";
    cout << "\n";
    return 0;
}
