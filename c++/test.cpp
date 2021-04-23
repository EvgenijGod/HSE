#include <algorithm>
#include <deque>
#include <iostream>
#include <map>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

struct A {
    void f() const {
        cout << "a\n";
    }
};

struct B:public A{
    virtual void f() const {
        cout << "b\n";
    }
};

int main() {
    char*str= new char;
    stpcpy(str, "hello");
    cout << str << "\n";
    delete str;
    return 0;
}
