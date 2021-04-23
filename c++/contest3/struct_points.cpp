#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    size_t n;
    cin >> n;
    vector<Point> points(n);
    for (size_t i = 0; i != n; ++i)
        cin >> points[i].x >> points[i].y;
    sort(
            points.begin(),
            points.end(),
            [](const Point &pnt1, const Point &pnt2) {
                return pnt1.x * pnt1.x + pnt1.y * pnt1.y <
                       pnt2.x * pnt2.x + pnt2.y * pnt2.y;
            }
    );
    for (size_t i = 0; i != n; ++i)
        cout << points[i].x << " " << points[i].y << "\n";
    return 0;
}
