#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

int main() {
    string request_in;
    vector<string> requests;
    while(getline(cin, request_in))
        requests.push_back(request_in);
    priority_queue<int> pr_queue;
    for (const string& request : requests) {
        if (request == "CLEAR") {
            while (!pr_queue.empty())
                pr_queue.pop();
        } else if (request == "EXTRACT") {
            if (pr_queue.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << pr_queue.top() << "\n";
                pr_queue.pop();
            }
        } else {
            int pushed_num = stoi(request.substr(4));
            pr_queue.push(pushed_num);
        }
    }
}

