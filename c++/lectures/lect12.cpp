#include <algorithm>
#include <iostream>
#include <list>
//#include <string>
#include <string.h>
#include <vector>

using namespace std;

struct Buffer { // POD ~ plain old data
    int x;
    double y;
};

int main() {
    char s1[100] = "hello";
    Buffer buf;

    char*p1 = s1;
    char * p2 = reinterpret_cast<char*>(&buf);

    strcpy(p2, s1);
    cout << p2 << "\n";
    cout << s1 << "\n";
    cout << buf.x << "\n";

}



#include <string>
#include <iostream>

using namespace std;

int main() {
    char buffer[100] = "";

/*    *buffer = 12349;           // warning, type(*buffer) - char, 12349 > char code
    cout << buffer << "\n";*/

    int* ptr = reinterpret_cast<int*>(buffer + 1);
    *ptr = 12349;
    cout << buffer << "\n";

    vector<int> v = {100500, 0xBEFF, -1, 4};
/*    for (int x : v)
        cout << x << " ";
    cout << "\n";*/


    for (int x : v)
        cout.write(reinterpret_cast<char*>(&x), sizeof(x));

#include <string>
#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int main() {
    vector<int> v(4);
    //fstream f("output");
    
    ifstream("output").read(
            reinterpret_cast<char*>(&*v.begin()),
            sizeof(int) * v.size()
            );
    ofstream g("output2");
    /*cin.read(
            reinterpret_cast<char*>(&v.front()),
            sizeof(int)*v.size()
            );*/
    for (int x : v)
        g << hex << x << " " << dec << x << "\n";
    // a.out >output
    // cat output
    // hd output
}
}




#include <iostream>
#include <vector>

using namespace std;

class C {
private:
    int* data;
    size_t sz;

public:
    C(size_t n) {
        data = new int[n];
        sz = n;
    }

    size_t  size() const {
        return sz;
    }

    int& operator[](size_t i) {
        return data[i];
    }

    int operator[](size_t i) const {
        return data[i];
    }

    C(const C& other) = delete; /*{
        data = new int[other.sz];
        sz = other.sz;
        for (size_t i = 0; i != sz; ++i)
            data[i] = other.data[i];
    }*/

    C(C&& other): data(other.data), sz(other.sz) {
        other.data = nullptr;
        other.sz = 0;
    }

    void swap(C& other) {
        std::swap(data, other.data);
        std::swap(sz, other.sz);
    }

    C&operator=(C&& other) {
        C tmp(std::move(other));
        swap(tmp);
        return *this;
    }

    C&operator = (const C& other) = delete; /*{
        C tmp(other);
        swap(tmp);
        return *this;
    }*/

    ~C() {
        delete [] data;
    }
};

int main() {
    C x(5);
    x[1] = 17;
    x[3] = -5;
    C y = x;
    for (size_t i = 0; i != y.size(); ++i)
        cout << x[i] << "\n";
    cout << "\n";
}
