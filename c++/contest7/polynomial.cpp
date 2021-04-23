#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

template<typename T>
class Polynomial;

template<typename T>
ostream &operator<<(ostream &out, Polynomial<T> p) {
    if (p.Degree() == -1) {
        out << T(0);
        return out;
    }
    for (long deg : p.degs) {
        if (p.coefs[deg] == T(0)) {
            continue;
        } else if (p.coefs[deg] == T(-1)) {
            out << '-';
            if (deg == 0)
                out << T(1);
        } else if (p.coefs[deg] == T(1)) {
            if (deg == 0) {
                if (deg == p.Degree())
                    out << T(1);
                else
                    out << '+' << T(1);
            } else if (deg != p.Degree()) {
                out << '+';
            }
        } else if (p.coefs[deg] < T(0)) {
            out << '-' << T(-1) * p.coefs[deg];
            if (deg != 0)
                out << '*';
        } else if (p.coefs[deg] > T(0)) {
            if (deg == p.Degree())
                out << p.coefs[deg];
            else
                out << '+' << p.coefs[deg];
            if (deg != 0)
                out << '*';
        }
        if (deg == 1)
            out << 'x';
        else if (deg != 0)
            out << "x^" << deg;
    }
    return out;
}

template<typename T>
class Polynomial {
public:
    map<long, T> coefs;
    set<long, greater<>> degs;

public:
    Polynomial() {
    }

    Polynomial(const vector<T> &in_coef) {
        for (size_t i = 0; i != in_coef.size(); ++i) {
            if (in_coef[i] != T(0)) {
                coefs[i] = in_coef[i];
                degs.insert(i);
            }
        }
    }

    Polynomial(const T &scalar) {
        if (scalar != T(0)) {
            coefs[0] = scalar;
            degs.insert(0);
        }
    }

    template<typename InIt>
    Polynomial(InIt first, InIt last) {
        size_t deg = 0;
        while (first != last) {
            if (*first != T(0)) {
                coefs[deg] = *first;
                degs.insert(deg);
            }
            ++deg;
            ++first;
        }
    }

    long Degree() const {
        if (degs.empty())
            return -1;
        return *degs.begin();
    }

    bool operator==(const Polynomial &other) const {
        if (degs != other.degs)
            return false;
        for (long deg : degs) {
            if (coefs.at(deg) != other.coefs.at(deg)) {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const Polynomial &other) const {
        return !(*this == other);
    }

    bool operator>=(const Polynomial &other) const {
        if (Degree() > other.Degree())
            return true;
        if (Degree() < other.Degree())
            return false;
        for (long deg = Degree(); deg != -1; --deg) {
            if (degs.find(deg) == degs.end()) {
                if (other.degs.find(deg) != other.degs.end())
                    return false;
                else
                    continue;
            } else {
                if (other.degs.find(deg) == other.degs.end()) {
                    return true;
                } else {
                    if (coefs.at(deg) != other.coefs.at(deg))
                        return coefs.at(deg) > other.coefs.at(deg);
                }
            }
        }
        return true;
    }

    auto begin() const {
        return coefs.begin();
    }

    auto end() const {
        return coefs.end();
    }

    const T operator[](const int &deg) const {
        if (deg > Degree())
            return T(0);
        if (degs.find(deg) != degs.end())
            return coefs.at(deg);
        else
            return T(0);
    }

    T operator()(const T &value) const {
        T res = coefs.at(Degree());
        for (long deg = Degree() - 1; deg != -1; --deg) {
            if (degs.find(deg) == degs.end())
                res = res * value;
            else
                res = res * value + coefs.at(deg);
        }
        return res;
    }

    Polynomial &operator+=(const Polynomial &other) {
        for (long deg : other.degs) {
            if (degs.find(deg) == degs.end()) {
                coefs[deg] = other.coefs.at(deg);
                degs.insert(deg);
            } else {
                coefs[deg] += other.coefs.at(deg);
            }
            if (coefs[deg] == T(0)) {
                coefs.erase(deg);
                degs.erase(deg);
            }
        }
        return *this;
    }

    Polynomial operator+(const Polynomial &other) const {
        Polynomial res = *this;
        res += other;
        return res;
    }

    Polynomial &operator-=(const Polynomial &other) {
        for (long deg : other.degs) {
            if (degs.find(deg) == degs.end()) {
                coefs[deg] = T(-1) * other.coefs.at(deg);
                degs.insert(deg);
            } else {
                coefs[deg] -= other.coefs.at(deg);
            }
            if (coefs[deg] == T(0)) {
                coefs.erase(deg);
                degs.erase(deg);
            }
        }
        return *this;
    }

    Polynomial operator-(const Polynomial other) const {
        Polynomial res = *this;
        res -= other;
        return res;
    }

    Polynomial &operator*=(const Polynomial &other) {
        map<long, T> tmp;
        for (long deg : degs) {
            for (long other_deg : other.degs) {
                tmp[deg + other_deg] += coefs[deg] * other.coefs.at(other_deg);
            }
        }
        coefs.clear();
        degs.clear();
        for (auto it = tmp.begin(); it != tmp.end(); ++it) {
            if (it->second != T(0)) {
                degs.insert(it->first);
                coefs[it->first] = it->second;
            }
        }
        return *this;
    }

    Polynomial operator*(const Polynomial &other) const {
        Polynomial res = *this;
        res *= other;
        return res;
    }

    Polynomial &operator*=(const T &scalar) {
        if (scalar == T(0))
            return Polynomial(0);
        for (long deg : degs)
            coefs[deg] *= scalar;
        return *this;
    }

    Polynomial operator*(const T &scalar) const {
        Polynomial res = *this;
        res *= scalar;
        return res;
    }

    Polynomial &operator/=(const T &scalar) {
        for (long deg : degs)
            coefs[deg] /= scalar;
        return *this;
    }

    Polynomial operator/(const T &scalar) const {
        Polynomial res = *this;
        res /= scalar;
        return res;
    }

    Polynomial operator/(const Polynomial &other) const {
        if (other.Degree() == -1)
            throw invalid_argument("Division by zero");
        if (Degree() < other.Degree())
            return Polynomial();
        Polynomial r = *this;
        Polynomial divider = other / other.coefs.at(other.Degree());
        Polynomial res;
        while (r.Degree() >= divider.Degree()) {
            long cur_deg = r.Degree() - divider.Degree();
            T cur_coef = r.coefs[r.Degree()];
            res.coefs[cur_deg] = cur_coef;
            res.degs.insert(cur_deg);
            Polynomial d;
            for (long other_deg : divider.degs) {
                d.coefs[other_deg + cur_deg] = divider.coefs[other_deg] * cur_coef;
                d.degs.insert(other_deg + cur_deg);
            }
            r -= d;
        }
        return res / other.coefs.at(other.Degree());
    }

    Polynomial operator%(const Polynomial &other) const {
        if (other.Degree() == -1)
            throw std::invalid_argument("Division by zero");
        if (Degree() < other.Degree())
            return *this;
        Polynomial d = *this / other;
        return *this - d * other;
    }

    Polynomial operator&(const Polynomial &other) const {
        if (Degree() == -1) {
            return Polynomial(0);
        }
        if (other.Degree() == -1) {
            if (degs.find(0) != degs.end()) {
                return Polynomial(coefs.at(0));
            } else {
                return Polynomial(0);
            }
        }
        Polynomial res;
        set<long, greater<>> tmp_deg;
        if (degs.find(0) != degs.end()) {
            res.coefs[0] = coefs.at(0);
            tmp_deg.insert(0);
        }
        Polynomial g = other;
        for (long deg = 1; deg <= Degree(); ++deg) {
            if (degs.find(deg) == degs.end()) {
                g *= other;
                continue;
            }
            for (long g_deg = 0; g_deg <= g.Degree(); ++g_deg) {
                if (g.degs.find(g_deg) != g.degs.end()) {
                    res.coefs[g_deg] += coefs.at(deg) * g.coefs[g_deg];
                    tmp_deg.insert(g_deg);
                }
            }
            g *= other;
        }
        for (long deg : tmp_deg) {
            if (res.coefs[deg] == T(0)) {
                res.coefs.erase(deg);
            } else {
                res.degs.insert(deg);
            }
        }
        return res;
    }

    Polynomial operator,(const Polynomial other) const {
        Polynomial p = *this / coefs.at(Degree());
        if (other == Polynomial(0))
            return p;
        if (p == Polynomial(0))
            return other / other.coefs.at(other.Degree());
        if (p >= other)
            return (other, p % other);
        else
            return (other, p);
    }
};

int main() {
    vector<double> v2 = {1, -2, 1};
    vector<double> v = {1, 1};
    Polynomial<double> p2(v2);
    Polynomial<double> p(v.begin(), v.end());
    cout << "p: " << p << "\n" << "p2: " << p2 << "\n";
    //cout << boolalpha << (p == p2);
/*    for (auto it = p.begin(); it != p.end(); ++it)
        cout << it->first << " " << it->second << "\n";*/
    cout << (p2 & p) << "\n";
}
