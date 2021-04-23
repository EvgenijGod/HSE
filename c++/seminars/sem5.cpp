***************************************************************
		СЕМИНАР 5 (07.02.2019)
***************************************************************

КР №2
D, E

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

map<string, int> final_standings(const vector<map<string, int>> standings) {
    map<string, int> res;
    for (size_t i = 0; i != standings.size(); ++i) {
        for (const auto &st : standings[i]) {
            if (res.find(st.first) == res.end()) {
                res[st.first] = st.second;
            } else {
                res[st.first] = max(res[st.first], st.second);
            }
        }
    }
    return res;
}

string concat(vector<string> &parts) {
    string res;
    for (size_t i = 0; i != parts.size(); ++i) {
        if (!res.empty()) {
            res += parts[i];
            res += " ";
        }
    }
    return res;
}

int main() {
    size_t m, n;
    cin >> m >> n;
    map<string, int> count;
    vector<string> parts(n);
    string ngram;
    for (size_t i = 0; i != n; ++i) {
        cin >> parts[i];
    }
    ngram = concat(parts);
    count[ngram] = 1;
    for (size_t i = n; i != m; ++i) {
        for (size_t j = 0; j != n; ++j) {
            parts[j] = parts[j + 1];
        }
        cin >> parts[n - 1];
        ++count[ngram];
    }
    vector<pair<string, int> > res(count.size());
    for (const auto &it : count) {
        res.push_back(make_pair(it.first, it.second));
    }
    sort(res.begin(),
         res.end(),
         [](const pair<string, int> &left, const pair<string, int> &right) {
             return tie(left.second, right.first) < tie(right.second, left.first);
         });
    for (const auto& it : res) {
        cout << it.first << " - " << it.second << "\n";
    }
    return 0;
}
**************************************************************************************

КОНТЕСТ №4

Е

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    map<int, int> pos;
    int id, follow;
    cin >> id >> follow;
    pos[-1] = id;
    pos[id] = -2;
    for (size_t i = 0; i != n; ++i) {
        cin >> id >> follow;
        if(pos.find(follow) == pos.end()) {
            pos[id] = pos[-1];
            pos[-1] = id;
        } else {
            pos[id] = pos[follow];
            pos[follow] = id;
        }
    }
    int st = -1;
    while(pos.find(st) == pos.end()) {
        cout << pos[st] << endl;
        st = pos[st];
    }
}

// or use list + map<int, it> that saves iterators of each player

int main() {
    size_t n;
    cin >> n;
    map<int, list<int>::iterator> m;
    list<int> storage;
    for (size_t i = 0; i != n; ++i) {
        int id, follow;
        cin >> id >>follow;
        if (m.find(follow) != m.end()) {
            storage.insert(m[follow], id);
            m[id] = m[follow];
            auto it = m[follow];
            --it;
            m[follow] = it;
        } else {
            m[id] = storage.begin();
            storage.push_front(id);
        }
    }
    for (const int &el : storage) {
        cout << el << "\n";
    }
}

**************************************************************************************

vector<int> v = {10, 20, 30, 40, 50};
    vector<int> a;
    copy(v.begin(), v.end(), std::inserter(a, a.begin())); 
    // если вместо inserter просто a.begin(), выйдет segmfault, т.к. copy не меняет capacity.
    // тогда либо a.resize(v.size()), либо использовать inserter
    // также remove() не уменьшает размер контейнера
