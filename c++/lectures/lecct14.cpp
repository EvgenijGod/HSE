умные указатели

#include <iostream>
#include <memory>

using namespace std;

unique_ptr<int> f() {
    return make_unique<int>(14);
}

int main() {
    //unique_ptr<int> ptr(new int(42));
    auto ptr = make_unique<int>(42);
    cout << *ptr << "\n";
    ptr.reset(new int(17));
    cout << *ptr << "\n";
    ptr = f();
    cout << *ptr << "\n";
    //auto ptr2 = ptr; // запрещено копирование
}

*************************************************************************

#include <iostream>
#include <memory>

using namespace std;

class C {
private:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
        if (counter == 300)
            throw counter;
        std::cout << "constructor C() " << id << "\n";
    }

    C(const C& other): id(++counter) {
        std::cout << "constructor C(const C&) " << id << " " << other.id << "\n";
    }

    C(const C&& other): id(++counter) {
        std::cout << "constructor C(const C&&) " << id << " " << other.id << "\n";
    }

    C& operator = (const C& other) {
        std::cout << "operator = (const C&) " << id << " " << other.id << "\n";
        return *this;
    }

    C& operator = (C&& other) {
        std::cout << "operator = (const C&&) " << id << " " << other.id << "\n";
        return *this;
    }

    ~C() {
        std::cout << "destructor C() " << id << "\n";
    }
};

int C::counter = 0;

int main() {
    try {
        auto c1 = make_unique<C>();
        auto c2 = make_unique<C>();
        auto c3 = make_unique<C>();
        c2.reset(new C); 
        c1.reset(); // c1.reset(nullptr)
        c3.reset();
    } catch(...) {
        cout << "Exception caught\n";
    }

}

***************************************************************************************

#include <iostream>
#include <memory>
#include <optional>
#include <string>

using namespace std;

class C{
public:
    C(const string& filename);
};

class D {
    // C* c = nullptr;
    //unique_ptr<C> c;
    optional<C> c;

public:
    D(){};

    void Init(const string& s) {
        //c.reset(new C(s));
        c.emplace(s);
    }

    void Do() const {
        if (c == nullptr) {
            //Init("");
        }
    }

    /*~D() {
        delete c;
    }*/
};

******************************************************************************************

shared ptr

#include <iostream>
#include <memory>
#include <string>

using namespace std;

template <typename T>
class SharedPtr {
private:
    T* ptr;
    int * links;
};

int main() {
    shared_ptr<int> up = make_shared<int>(42);
    auto ptr2 = up; // две ссылки на один указатель
}

******************************************************************************************

наследование

#include <iostream>
#include <string>
// #include <variant>
#include <vector>

using namespace std;

struct Point {
    double x, y;
};

class Figure {
protected:
    Point center;
    int colour;

public:
    Figure(double x, double y, double c): center(x,y), colour(c){}

    void draw() const {
        cout << "Not implemented\n";
    }
};

class Circle: public Figure {
private:
    double radius;
/*    Point center;
    int colour;*/

public:
    Circle(double r, double x, double y, int c):
    Figure(x,y,c),
    radius(r){}
    void draw() const {
        cout << "Circle:\n" << radius << " " << center.x << " " << center.y << " " << colour << "\n";
    };
};

class Square: public Figure {
    double side;
/*    Point center;
    int colour;*/

public:
    Square(double s, double x, double y, int c):
            Figure(x,y,c),
            side(s){}

    void draw() const {
        cout << "Square:\n" << side << " " << center.x << " " << center.y << " " << colour << "\n";
    }
};

int main() {
    vector<Figure> figures;
    for (const auto& figure : figures)
        figure.draw();
    // vector<variant<Circle,Square>>figures; // c++17
}

