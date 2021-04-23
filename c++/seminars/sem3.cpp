*******************************************************************************
	СЕМИНАР 3 (24.01.2019)
*******************************************************************************

vector <vector<int> > v (n, vector<int>(n,-2))

*******************************************************************************
	ЗАДАЧА Е (КР1)

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

pair<size_t, size_t> FindVowels(const string& text, size_t st_pos) {
    if (st_pos >= text.size())
        return {string::npos, 0};
    vector<char> vowels = {'a','e','i','o','u','y'};
    size_t win_len = 0;
    size_t ans_pos = string::npos;
    size_t ans_len = 0;
    for (size_t pos = st_pos; pos < text.size(); ++pos) {
        if (find(vowels.begin(), vowels.end(), text[pos]) == vowels.end()) {
            if (win_len != 0)
                break;
            continue;
        }
        ++win_len;
        if (ans_len == string::npos)
            ans_pos = pos;
        ans_len = win_len;
    }
    return {ans_pos, ans_len};
}

********************************************************************************
	ЗАДАЧА F (КР2)

#include <iostream>
#include <vector>

using namespace std;

int main() {
    size_t n, m;
    cin >> n;
    vector<vector<string> > v(n);
    size_t maxm = 0;
    for (size_t j = 0; j < n; ++j) {
        cin >> m;
        v[j].resize(m);
        for (size_t i = 0; i < m; ++i) {
            cin >> v[j][i];
        }
        maxm = max(maxm, m);
    }
    for (size_t j = 0; j < maxm; ++j) {
        for (size_t i = 0; i < v.size(); ++i) {
            string output;
            if (j < v[i].size()) {
                output = v[i][j];
            }
            cout << output << "\t";
        }
        cout << "\n";
    }
    return 0;
}

********************************************************************************

		SET, UNORDERED_SET

********************************************************************************

		SET			UNORDERED_SET		MULTISET
---------------------------------------------------------------------------------
algo		BST			hash_table		BST
find		log			amort O(1)		log
erase		log			amort O(1)		log
insert		log			amort O(1)		log
is_ordered	 +			     -			 +
duplicates	 -			     -			 +


s.lower_bound(x) returns iterator of first el >= x
s.upper_bound(x) returns iterator of first el > x
can be used in set, multiset due to BST structure;

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void PrintSet(const set<int>& s) {
    for (const auto&el: s) {
        cout << el<< " ";
    }
    cout<< endl;
}

int main() {
    set<int> s;
    s.insert(1);
    s.insert(10);
    s.insert(2);
    s.insert(7);
    s.insert(7);

    cout << *(s.lower_bound(7)) << " ";
    auto it = s.upper_bound(10);
    if (it != s.end())
        cout << *(s.upper_bound(10)) << endl;
    PrintSet(s);
/*    s.erase(7);
    auto it = s.find(2);
    s.erase(it);
    s.erase(s.begin());
    PrintSet(s);*/
    cout << s.count(7) << ' ' << s.count(12345) << endl;

    multiset<int> ms;
    ms.insert(7);
    ms.insert(7);
    ms.insert(7);
    ms.insert(3);
    ms.insert(3);
    for (const auto& el : ms)
        cout << el << " ";
    cout << endl;
    cout << ms.count(7) << ' ' << ms.count(12345) << endl;
}

*********************************************************************************

		LAMBDA-FUNCTIONS

*********************************************************************************
#include <iostream>
#include <vector>
using namespace std;

auto CreateLambda (const string& identifier) {
    vector<int> v (1000, 0);
    return [identifier, v] (auto x) mutable {
        cout << "function: " << identifier << endl;
        v.push_back(x);
        cout << "Vector size: " << v. size() << endl;
    };
}

int main() {
    const auto mul = [](auto a,auto b) {
        return a*b;
    };
    cout << mul(2,3)<<endl;
    auto SuperLambda = CreateLambda("super lambda");
    SuperLambda(0);
    SuperLambda(1);
    SuperLambda(2);
}


***********************************************************************************

		STRUCT, OPERATORS

***********************************************************************************
#include <iostream>
#include <vector>
#include <set>
#include <tuple>

using namespace std;

struct Time {
    int hours{0};
    int minutes{0};
    int seconds{0};

    int operator()(const string& field) {
        if (field == "h")
            return hours;
        if (field == "m")
            return minutes;
        if (field == "s")
            return seconds;
    }
};

bool operator<(const Time& first, const Time& second) {
    return make_tuple(first.hours, first.minutes, first.seconds) <
    make_tuple(second.hours, second.minutes, second.seconds)
}

int main() {
    Time t;
    cout << t("h") << " " << t("m") << " " << t("s") << endl;
    cout << t.hours << " " << t.minutes << " " << t.seconds << endl;
}

