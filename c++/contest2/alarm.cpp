#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
    int weekday, hour, minutes, n;
    cin >> weekday >> hour >> minutes;
    cin >> n;
    vector<vector<int> > alarm;
    alarm.resize(n);
    for (size_t i = 0; i != n; ++i) {
        alarm[i].resize(3);
        for (size_t j = 0; j != 3; ++j)
            cin >> alarm[i][j];
    }
    tuple<int, int, int> closest;
    int min_time_difference = 8 * 24 * 60;
    int cur_time = weekday * 24 * 60 + hour * 60 + minutes;
    for (size_t i = 0; i != n; ++i) {
        int al_time;
        if (alarm[i][0] == 0) {
            if (alarm[i][1] * 60 + alarm[i][2] == hour * 60 + minutes) {
                get<0>(closest) = weekday;
                get<1>(closest) = hour;
                get<2>(closest) = minutes;
                break;
            } else if (alarm[i][1] * 60 + alarm[i][2] < hour * 60 + minutes) {
                al_time = (weekday + 1) * 24 * 60 + alarm[i][1] * 60 + alarm[i][2];
                if ((al_time - cur_time) < min_time_difference) {
                    min_time_difference = al_time - cur_time;
                    get<0>(closest) = (weekday + 1) % 7;
                    get<1>(closest) = alarm[i][1];
                    get<2>(closest) = alarm[i][2];
                }
            } else {
                al_time = weekday * 24 * 60 + alarm[i][1] * 60 + alarm[i][2];
                if ((al_time - cur_time) < min_time_difference) {
                    min_time_difference = al_time - cur_time;
                    get<0>(closest) = weekday;
                    get<1>(closest) = alarm[i][1];
                    get<2>(closest) = alarm[i][2];
                }
            }
        } else {
            if (alarm[i][0] * 24 * 60 + alarm[i][1] * 60 + alarm[i][2] < cur_time) {
                al_time = (alarm[i][0] + 7) * 24 * 60 + alarm[i][1] * 60 + alarm[i][2];
                if ((al_time - cur_time) < min_time_difference) {
                    min_time_difference = al_time - cur_time;
                    get<0>(closest) = alarm[i][0];
                    get<1>(closest) = alarm[i][1];
                    get<2>(closest) = alarm[i][2];
                }
            } else {
                al_time = alarm[i][0] * 24 * 60 + alarm[i][1] * 60 + alarm[i][2];
                if ((al_time - cur_time) < min_time_difference) {
                    min_time_difference = al_time - cur_time;
                    get<0>(closest) = alarm[i][0];
                    get<1>(closest) = alarm[i][1];
                    get<2>(closest) = alarm[i][2];
                }
            }
        }
    }
    cout << get<0>(closest) << " " << get<1>(closest) << " " << get<2>(closest) << "\n";
    return 0;
}

