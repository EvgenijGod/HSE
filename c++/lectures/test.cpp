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

    C(const C&) {
        id = ++counter;
        cout << "C(const C&) " << id << "\n";
    }

    C(C&&) {
        id = ++counter;
        cout << "C(C&&) " << id << "\n";
    }

    ~C() {
        cout << "~C() " << id << "\n";
    }
};

int C::counter = 0;

int main() {
    auto addr = new int(42);
    cout << addr << "\n";
    *addr = 17;
    cout << *addr << "\n";
    delete addr;
}

//! g++ -std=c++11 -fno-elide-constructors test.cpp -o test.out && ./test.out
