#include <iostream>
#include <string>

using namespace std;

int main() {
    int k;
    string n;
    cin >> k >> n;
    int rmn = 0;
    for (char digit : n)
        rmn = (rmn * 10 + (digit - '0')) % k;
    cout << rmn << "\n";
    return 0;
}

