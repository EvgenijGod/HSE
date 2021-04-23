#include <iostream>

class C {
public:
    C() {
        std::cout << "Constructor called\n";
    }
    C(const C& other) {
        std::cout << "Copy constructor called\n";
    }
    C(C&& other) {
        std::cout << "Move constructor called\n";
    }
    C& operator = (const C& other) {
        std::cout << "Assignment operator called\n";
    }
    ~C() {
        std::cout << "Destructor called\n";
    }
};


int main() {
    C c1;
    C c2{std::move(c1)}; // copy constructor
    //c1 = c2; // assignment
    C c{C()}; // temporary variable
    //c.f(42);
    //g(c, 42);
    vector<C> objects(3);
    cout << "Vector has been created\n\n";
    C c;
    cout << "Push back\n";
    objects.push_back(move(c));
    cout << "Done\n\n";
}

#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    vector<string> v;
    for (size_t i = 0; i != 10000; ++i) {
        string s;
        for (size_t j = 0; j != 10000; ++j) {
            string s(10000, '@');
            v.push_back(move(s)); // counts s as temporary
        }
        cout << v.size() << "\n";
    }
}


*************************************************************

#include <array>
#include <iostream>

using namespace std;

template <typename T, size_t N>
class Matrix;

template<typename T, size_t N>
class MatrixIterator {
private:
    Matrix <T, N> matrix;
    size_t row, column;

public:
    MatrixIterator(
            Matrix <T, N> &m,
            size_t i,
            size_t j
    ) {
        //matrix = m;
    }
};

template<typename T, size_t N>
class Matrix {
private:
    MatrixIterator
    array<array<T, N>, N> data;

public:
    const array<T, N> &operator[](size_t row) const { // for reading-only
        return data[row];
    }

    array<T, N> &operator[](size_t row) { // can be changed
        return data[row];
    }
};

template<typename T, size_t N>
ostream &operator<<(
        ostream &out,
        const Matrix<T, N> &m
) {
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            if (j > 0)
                out << "\t";
            out << m[i][j];
        }
        out << "\n";
    }
    return out;
}

template<typename T, size_t N>
Matrix<T, N> operator-(
        const Matrix<T, N> &m1,
        const Matrix<T, N> &m2
) {
    Matrix<T, N> result;
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }
    return result;
}

template<typename T, size_t N>
Matrix<T, N> &operator-=(
        Matrix<T, N> &m1,
        const Matrix<T, N> &m2
) {
    for (size_t i = 0; i != N; ++i) {
        for (size_t j = 0; j != N; ++j) {
            m1[i][j] -= m2[i][j];
        }
    }
    return m1;
}

int main() {
    Matrix<int, 2> A;
    A[0][0] = 1;
    A[0][1] = 2;
    A[1][0] = 3;
    A[1][1] = 4;

    Matrix<int, 2> B;
    B[0][0] = B[1][1] = 0;
    B[1][0] = B[0][1] = 1;
    A -= B;
    cout << A << "\n";
}

// перегрузка операторов
// ++a++ ~ ++(a++)
// ++ -- -> [] () унарные - +
// бинарные + - * / %
// == != < > <= >=
// && || !
// побитовые & | ~ ^
// a, b
// = @=
// унарные * &
