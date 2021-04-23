#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Student {
    string name;
    int mark = 0;
};

int mark_in_contest(const vector<Student>& contest, const string& name) {
    for (size_t i = 0; i != contest.size(); ++i) {
        if (contest[i].name == name)
            return contest[i].mark;
    }
    return 0;
}

int main() {
    size_t n;
    cin >> n;
    set<string> names;
    vector<vector<Student> > contests(n);
    for (size_t i = 0; i != n; ++i) {
        size_t k;
        cin >> k;
        contests[i].resize(k);
        for (size_t j = 0; j != k; ++j) {
            cin >> contests[i][j].name >> contests[i][j].mark;
            names.insert(contests[i][j].name);
        }
    }
    for (const string& student : names) {
        cout << student;
        for (size_t i = 0; i != n; ++i) {
            cout << "\t" << mark_in_contest(contests[i], student);
        }
        cout << "\n";
    }
    return 0;
}

