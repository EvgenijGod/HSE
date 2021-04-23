#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main(int argc, char *argv[]) {
    int n = atoi(argv[1]);
    cout << "N-grams size: " << n << endl;
    char c;
    string context;
    map<string, vector<int> > freqs;
    while (cin.get(c)) {
        if (context.size() == n) {
            if (freqs.find(context) == freqs.end()) {
                freqs[context].resize(256);         // 256 chars
            }
            ++freqs[context][static_cast<unsigned char>(c)];
        }
        context.push_back(c);
        if (context.size() > n)
            context.erase(context.begin());
    }
    context = "beginning";
    context.resize(n);
    cout << "Context is: " << context << endl;
    std::random_device rd; // generates random nums
    std::mt19937 generator(rd());
    for (int i = 0; i < 2000; ++i) {
        const auto &freqs_for_context = freqs[context];
        discrete_distribution<> distribution(freqs_for_context.begin(), freqs_for_context.end());
        char c = distribution(generator);
        cout.put(c);
        context.push_back(c);
        context.erase(context.begin());
    }
    cout << "\n";
}
