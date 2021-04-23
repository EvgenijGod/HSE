#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool operator<(const Date &d1, const Date &d2) {
    return tie(d1.year, d1.month, d1.day) < tie(d2.year, d2.month, d2.day);
}

struct Student {
    string name;
    string surname;
    int points;
    Date date_of_birth;
    vector<string> preferred_unis;
};

int main() {
    size_t n;
    cin >> n;
    map<string, size_t> quota;
    set<string> unis;
    for (size_t i = 0; i != n; ++i) {
        string uni;
        size_t in_quota;
        cin >> uni >> in_quota;
        quota[uni] = in_quota;
        unis.insert(uni);
    }
    size_t m;
    cin >> m;
    vector<Student> students(m);
    for (size_t i = 0; i != m; ++i) {
        cin >> students[i].name >> students[i].surname >> students[i].date_of_birth.day >>
            students[i].date_of_birth.month >> students[i].date_of_birth.year >> students[i].points;
        size_t num_of_preferred_unis;
        cin >> num_of_preferred_unis;
        students[i].preferred_unis.resize(num_of_preferred_unis);
        for (size_t j = 0; j != num_of_preferred_unis; ++j)
            cin >> students[i].preferred_unis[j];
    }
    sort(students.begin(),
         students.end(),
         [](const Student &std1, const Student &std2) {
             return tie(std1.points, std2.date_of_birth, std2.surname, std2.name) >
                    tie(std2.points, std1.date_of_birth, std1.surname, std1.name);
         });
    map<string, vector<string> > universities;
    for (const Student& student : students) {
        for (const string& uni : student.preferred_unis) {
            if (quota[uni] > 0) {
                universities[uni].push_back(student.name + ' ' + student.surname);
                --quota[uni];
                break;
            }
        }
    }
    for (const string& uni : unis) {
        cout << uni;
        for (const string& student : universities[uni])
            cout << "\t" << student;
        cout << "\n";
    }
    return 0;
}

