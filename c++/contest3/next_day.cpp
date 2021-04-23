#include <iostream>

using namespace std;

struct Date {
    int day = 1;
    int month = 1;
    int year = 1;
};

bool is_a_leap_year(const int& year) {
    if (year % 400 == 0)
        return true;
    if (year % 4 == 0) {
        if (year % 100 == 0)
            return false;
        return true;
    }
    return false;
}

Date next_day(Date cur_date) {
    if (cur_date.day <= 27)
        return {cur_date.day + 1, cur_date.month, cur_date.year};
    if (cur_date.day == 28 || cur_date.day == 29) {
        if (cur_date.month != 2) {
            return {cur_date.day + 1, cur_date.month, cur_date.year};
        } else {
            switch (cur_date.day) {
                case(28) : {
                    if (is_a_leap_year(cur_date.year))
                        return {29, 2, cur_date.year};
                    return {1, 3, cur_date.year};
                }
                case(29) :
                    return {1, 3, cur_date.year};
            }
        }
    }
    if (cur_date.day == 30) {
        switch (cur_date.month) {
            case(4):
            case(6):
            case(9):
            case(11):
                return {1, cur_date.month + 1, cur_date.year};
            case(1):
            case(3):
            case(5):
            case(7):
            case(8):
            case(10):
            case(12):
                return {31, cur_date.month, cur_date.year};
        }
    }
    if (cur_date.day == 31) {
        if (cur_date.month == 12)
            return {1, 1, cur_date.year + 1};
        return {1, cur_date.month + 1, cur_date.year};
    }
}


int main() {
    Date date;
    cin >> date.day >> date.month >> date.year;
    Date res_date = next_day(next_day(date));
    cout << res_date.day << " " << res_date.month << " " << res_date.year << "\n";
    return 0;
}
