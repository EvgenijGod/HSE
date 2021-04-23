#include <algorithm>
#include <cctype>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string contest_in;
    vector<int> contest_numbers;
    map<int, vector<string>> contests;
    while (getline(cin, contest_in)) {
        stringstream ss(contest_in);
        int contest_num;
        ss >> contest_num;
        contest_numbers.push_back(contest_num);
        size_t contest_size;
        ss >> contest_size;
        vector<string> tasks_done;
        string task_in;
        bool isDigit = true;
        while (ss >> task_in) {
            if (!isdigit(task_in[0]))
                isDigit = false;
            tasks_done.push_back(task_in);
        }
        for (int i = 1; i != contest_size + 1; ++i) {
            if (isDigit) {
                if (find(tasks_done.begin(), tasks_done.end(), to_string(i))
                    == tasks_done.end())
                    contests[contest_num].push_back(to_string(i));
            } else {
                string s;
                s.push_back(char(i + 'A' - 1));
                if (find(tasks_done.begin(), tasks_done.end(), s)
                    == tasks_done.end())
                    contests[contest_num].push_back(s);
            }
        }
    }
    for (const int &num : contest_numbers) {
        cout << num;
        for (const string &el : contests[num]) {
            cout << " " << el;
        }
        cout << "\n";
    }
}

