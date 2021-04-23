#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>

using namespace std;

struct Requests {
    char op;
    string word;
};

vector<Requests> readRequests() {
    vector<Requests> requests;
    char request;
    cin >> request;
    string word;
    while (request != '#') {
        cin >> word;
        requests.push_back({request, word});
        cin >> request;
    }
    return requests;
}

int main() {
    vector<Requests> reqs = readRequests();
    unordered_set<string> words;
    for (const Requests& req : reqs) {
        if (req.op == '?') {
            if (words.find(req.word) == words.end())
                cout << "NO\n";
            else
                cout << "YES\n";
        }
        if (req.op == '+') {
            words.insert(req.word);
        }
        if (req.op == '-') {
            words.erase(req.word);
        }
    }
    return 0;
}

