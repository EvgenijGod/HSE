#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

vector<string> readLines() {
    string line;
    vector<string> lines;
    while (getline(cin, line))
        lines.push_back(line);
    return lines;
}

int main() {
    vector<string> lines = readLines();
    set<string> directories;
    for (const string &line : lines) {
        size_t pos = 0;
        while (line.find('/', pos) != string::npos) {
            if (line.find('/', pos) == line.size() - 1) {
                pos = line.size();
                continue;
            } else {
                directories.insert(line.substr(0, line.find('/', pos) + 1));
                pos = line.find('/', pos) + 1;
            }
        }
    }
    for (const string& directory : directories) {
        cout << directory << "\n";
    }
    return 0;
}

