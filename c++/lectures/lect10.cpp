#include <array>
#include <iostream>

using namespace std;

template<typename T, size_t N>
class Matrix;

template<typename T, size_t N>
class ConstMatrixIterator {
private:
    const Matrix<T, N> matrix;
    size_t row, column;

public:
    ConstMatrixIterator(
            Matrix<T, N> &m,
            size_t i,
            size_t j
    ) : matrix(m), row(i),
        column(j) { // единственный способ проинициализировать поля класса (в том же порядке, как описаны в классе)

    }

    bool operator==(ConstMatrixIterator other) const {
        return row == other.row && column == other.column;
    }

    bool operator!=(ConstMatrixIterator other) const {
        //return !(*this == other);
        return !(operator==(other));
    }

    const T &operator*() const {
        return matrix[row][column];
    }

    ConstMatrixIterator& operator ++ () {
        ++column;
        if (column == N) {
            ++row;
            column = 0;
        }
        return *this;
    }
};

template<typename T, size_t N>
class Matrix {
private:
    array<array<T, N>, N> data;

public:
    ConstMatrixIterator<T, N> begin() const {
        return {*this, 0, 0};
    }

    ConstMatrixIterator<T, N> end() const {
        return {*this, N, 0};
    }

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

    A -= B;

    cout << A << "\n";

    /*for (auto it = A.begin(); it != A.end(); ++it) {
        cout << *it << " ";
    }*/
    const auto& C = A;

    for (const auto& elem : C)
        cout << elem << " ";
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

*****************************************************************************

	ASSERT

*****************************************************************************

#include <cassert>
#include <iostream>

using namespace std;

int main() {
    cout << "Step 1\n";
    assert(2 * 2 == 4);
    
    cout << "Step 2\n";
    assert(2 * 2 == 5);
    
    cout << "Step 3\n";
}

*****************************************************************************
#include <iostream>

using namespace std;

class C {
    static int counter; // global in class C; one for whole class, not for a variable
    int id;

/*    static void foo {

    };*/                    // can't be used outside the class
public:
    C() {
        id = ++counter;
        cout << "C() " << id << "\n";
    }

    C(const C &) {
        id = ++counter;
        cout << "C(const C&) " << id << "\n";
    }

    C(C &&) {
        id = ++counter;
        cout << "C(C&&) " << id << "\n";
    }

    ~C() {
        cout << "~C() " << id << "\n";
    }
};

int C::counter = 0;

int main() {
/*    int* addr = new int(42);
    cout << addr << "\n";
    *addr = 17;
    cout << *addr << "\n";
    delete addr;*/

    int x = 42;
    int* addr = &x;

    cout << x << "\n";
    cout << &addr << "\n";
    cout << addr << "\n";
    cout << *addr << "\n";

    auto addr = new C;
    delete addr;

    addr = new C;
    delete addr;
/*    C* addr = new C();
    cout << "new C created\n";
    delete addr;
    cout << "new C has been deleted\n";*/
    /*
}

//! g++ -std=c++11 -fno-elide-constructors test.cpp -o test.out && ./test.out
int main() {
    C a = C(C());
}

//! g++ -std=c++11 -fno-elide-constructors test.cpp -o test.out && ./test.out

********************************************************************************


