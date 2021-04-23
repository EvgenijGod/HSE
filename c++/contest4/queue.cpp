#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int main () {
    vector<string> requests;
    string request_in;
    while(getline(cin, request_in))
        requests.push_back(request_in);
    queue<int> queue;
    for (const string& request : requests) {
        if (request == "exit") {
            cout << "bye\n";
            return 0;
        } else if (request == "front") {
            if (queue.empty()) {
                cout << "error\n";
            } else {
                cout << queue.front() << "\n";
            }
        } else if (request == "pop") {
            if (queue.empty()) {
                cout << "error\n";
            } else {
                cout << queue.front() << "\n";
                queue.pop();
            }
        } else if (request == "size") {
            cout << queue.size() <<"\n";
        } else if (request == "clear") {
            while (!queue.empty())
                queue.pop();
            cout << "ok\n";
        } else {
            int pushed_num = stoi(request.substr(5));
            queue.push(pushed_num);
            cout << "ok\n";
        }
    }
    return 0;
}

