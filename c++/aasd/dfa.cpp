nclude <algorithm>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int main() {
      int n;
          cin >> n;
              vector <vector<int>> transitions(n);
                  vector<bool> accepted(n, false);
                      for (size_t i = 0; i != n; ++i) {
                                transitions[i].resize(26, -1);
                                    }
                          for (size_t i = 0; i != n; ++i) {
                                    cin >> accepted[i];
                                            int t;
                                                    cin >> t;

                                                for (size_t j = 0; j != t; ++j) {
                                                                          char transition_letter;
                                                                                      int transition_state;
                                                                                                  cin >> transition_letter >> transition_state;
                                                                                                              transition[i][transition_letter - 'a'] = transition_state;
                                                                                                                      }
                                                                }

}

