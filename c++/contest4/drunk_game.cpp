#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    deque<int> first_pl;
    deque<int> second_pl;
    for (size_t i = 0; i != 5; ++i) {
        int card;
        cin >> card;
        first_pl.push_back(card);
    }
    for (size_t i = 0; i != 5; ++i) {
        int card;
        cin >> card;
        second_pl.push_back(card);
    }
    int turns = 0;
    while (!first_pl.empty() && !second_pl.empty() && turns != 1000000) {
        ++turns;
        int first_card = first_pl[0];
        first_pl.pop_front();
        int second_card = second_pl[0];
        second_pl.pop_front();
        if (((first_card == 0 && second_card == 9) || first_card > second_card) &&
            !(first_card == 9 && second_card == 0)) {
            first_pl.push_back(first_card);
            first_pl.push_back(second_card);
        } else {
            second_pl.push_back(first_card);
            second_pl.push_back(second_card);
        }
    }
    if (second_pl.empty()) {
        cout << "first " << turns << "\n";
    } else if (first_pl.empty()) {
        cout << "second " << turns << "\n";
    } else {
        cout << "botva\n";
    }
    return 0;
}

