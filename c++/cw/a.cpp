#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    size_t n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<vector<int> > field;
    field.resize(n);
    for (size_t i = 0; i != n; ++i) {
        field[i].resize(m);
        for (size_t j = 0; j != m; ++j)
            field[i][j] = 0;
    }
    for (size_t i = 0; i != k; ++i) {
        int x, y;
        cin >> x >> y;
        field[x - 1][y - 1] = 9;
    }
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j) {
            if (field[i][j] != 9) {
                if (j >= 1) {
                    if (field[i][j - 1] == 9)
                        ++field[i][j];
                    if (i >= 1)
                        if (field[i - 1][j - 1] == 9)
                            ++field[i][j];
                    if (i < n - 1)
                        if (field[i + 1][j - 1] == 9)
                            ++field[i][j];
                }
                if (j < n - 1) {
                    if (field[i][j + 1] == 9)
                        ++field[i][j];
                    if (i >= 1)
                        if (field[i - 1][j + 1] == 9)
                            ++field[i][j];
                    if (i < n - 1)
                        if (field[i + 1][j + 1] == 9)
                            ++field[i][j];
                }
                if (i >= 1) {
                    if (field[i - 1][j] == 9)
                        ++field[i][j];
                }
                if (i < n - 1)
                    if (field[i + 1][j] == 9)
                        ++field[i][j];
            }
        }
    }
    for (size_t i = 0; i != n; ++i) {
        for (size_t j = 0; j != m; ++j)
            if (field[i][j] == 9)
                cout << "* ";
            else
                cout << field[i][j] << " ";
        cout << "\n";
    }
    return 0;
}
