#include <iostream>
#include <vector>

using namespace std;

bool is_associative(const vector<vector<int> >& m_op, const size_t &n) {
    for (size_t i = 0; i != n; ++i)
        for (size_t j = 0; j != n; ++j)
            for (size_t k = 0; k != n; ++k)
                if (m_op[m_op[i][j]][k] != m_op[i][m_op[j][k]])
                    return false;
    return true;
}

int main() {
    size_t n;
    cin >> n;
    vector<vector<int> > m_op;
    m_op.resize(n);
    for (size_t i = 0; i != n; ++i) {
        m_op[i].resize(n);
        for (size_t j = 0; j != n; ++j)
            cin >> m_op[i][j];
    }
    if (is_associative(m_op, n))
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}

