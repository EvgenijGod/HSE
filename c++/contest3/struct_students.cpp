#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Students {
    string name;
    string surname;
    int date;
    int month;
    int year;
};

struct Request {
    string request;
    int std_num;
};

int main() {
    size_t n;
    cin >> n;
    vector<Students> students(n);
    for (size_t i = 0; i != n; ++i)
        cin >> students[i].name >> students[i].surname >>
            students[i].date >> students[i].month >> students[i].year;
    size_t m;
    cin >> m;
    vector<Request> requests(m);
    for (size_t i = 0; i != m; ++i)
        cin >> requests[i].request >> requests[i].std_num;
    for (size_t i = 0; i != m; ++i) {
        if (requests[i].std_num > n || requests[i].std_num == 0)
            cout << "bad request\n";
        else if (requests[i].request == "name")
            cout << students[requests[i].std_num - 1].name << " " <<
                 students[requests[i].std_num - 1].surname << "\n";
        else if (requests[i].request == "date")
            cout << students[requests[i].std_num - 1].date << '.' <<
                 students[requests[i].std_num - 1].month << '.' <<
                 students[requests[i].std_num - 1].year << "\n";
        else
            cout << "bad request\n";
    }
    return 0;
}

