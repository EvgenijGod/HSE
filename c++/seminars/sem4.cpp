******************************************************************
		СЕМИНАР 4 (31.01.2019)
******************************************************************

КОНТЕСТ №3

#include <set>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

void solve_j(vector<pair<string, int> >& scores) {
    map <string, pair<long long, long long> > ans;
    for (size_t i = 0; i < scores.size(); ++i) {
        ans[scores[i].first].first += scores[i].second;
        ans[scores[i].first].second += 1;

        cout << ans[scores[i].first].first / ans[scores[i].first].second << "\n";
    }
}

int main() {

}

***********************************************************************************

STACK
DEQUE
QUEUE

***********************************************************************************

push() // puts el into stack
top()  // returns top el in stack
pop()  // removes an el in stack

***********************************************************************************

N-GRAMS

***********************************************************************************

- n consecutive symbols


