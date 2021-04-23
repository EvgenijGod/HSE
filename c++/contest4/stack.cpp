#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    vector<string> requests;
    string request_in;
    while (getline(cin, request_in))
        requests.push_back(request_in);
    stack<int> stck;
    for (const string &request : requests) {
        if (request == "exit") {
            cout << "bye\n";
            return 0;
        } else if (request == "size") {
            cout << stck.size() << "\n";
        } else if (request == "back") {
            cout << stck.top() << "\n";
        } else if (request == "pop") {
            cout << stck.top() << "\n";
            stck.pop();
        } else if (request == "clear") {
            while (!stck.empty())
                stck.pop();
            cout << "ok\n";
        } else {
            int pushed_num = stoi(request.substr(5));
            stck.push(pushed_num);
            cout << "ok\n";
        }
    }
    return 0;
}

