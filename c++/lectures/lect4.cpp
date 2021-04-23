#include <algorithm>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;


struct Student {
    string name;
    string surname;
    double rating = 0.0;
    int group;
};


ostream& operator<<(ostream& out,const Student& s) {
    out << s.name << " "
        << s.surname << " "
        << s.rating << " "
        << s.group;
    return out;

}


bool operator<(const Student& s1, const Student& s2) {
    return s1.rating > s2.rating;
}

int main() {
    //Student s{"Ivan", "Ivanov", 5.0, 181};
    //cout << s.surname;
    vector<Student> students {
            {"I", "P", 3.4, 182},
            {"a", "b", 2.0, 189},
            {"a", "b", 10.0, 188},
    };
    sort(
            students.begin(),
            students.end(),
            [](const auto& s1, const auto& s2) {
                return s1.rating > s2.rating;
            }
            );
    sort(
            students.begin(),
            students.end(),
            [](const auto& s1, const auto& s2) {
                return tie(s1.surname, s1.name, s1.group)
                < tie(s2.surname, s2.name, s2.group);
                /*                if (s1.surname != s2.surname)
                    return s1.surname < s2.surname;
                else if (s1.name != s2.name)
                    return s1.name < s2.name;
                else
                    return s1.group < s2.group;*/
            }
    );
    sort(students.begin(), students.end());
    for (const Student& s : students) {
        /*cout << s.name << " "
        << s.surname << " "
        << s.rating << " "
        << s.group << "\n";*/

        cout << s << "\n";
    }
}

*******************************************************************

bool cmpabs(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    vector<int> v = {2, -12, 85, 0,  -6   };
    //               b  b+1 b+2 b+3 b+4 b+5=e
    //            re                rb
    //sort(v.begin() + 1, v.begin() + 4); //[b+1,b+4)
    //sort(v.rbegin(), v.rend()); // reversed sort
    //sort(v.begin(), v.end(), cmpabs);
    sort(
            v.begin(),
            v.end(),
            [](int a, int b) {              // lambda-function
                return abs(a) < abs(b);
            }
            );
    for (int x : v)
        cout << x << "\n";
}

********************************************************************

#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    map<string, int> freqs;
    string word;
    while (cin >> word)
        ++freqs[word];      //default value of int == 0
    for (const auto& item : freqs)
        cout << item.first << " " << item.second << "\n";

    vector<pair<string, int> > words(
            freqs.begin(),
            freqs.end()
            );
/*    words.reserve(freqs.size());
    for (const auto& item : freqs)
        word.push_back(item);*/
    sort(
            words.begin(),
            words.end(),
            [](const auto& p1, const auto& p2) {
                return p1.second > p2.second;
            }
            );
    for (const auto& [word, freq] : words)
        cout << word << "\t" << freq << "\n";
}


