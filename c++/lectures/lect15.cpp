#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct Point{
    double x;
    double y;

    Point(double first, double second) {
        x = first;
        y = second;
    }
};

ostream&operator<<(ostream& out, Point p) {
    out << p.x << " " << p.y;
    return out;
}

class Figure{
protected:
    Point center;
    int colour;

public:
    Figure(double x, double y, int c):center(x, y), colour(c) {
    }

    virtual void draw() const = 0;
};

class Circle:public Figure{
private:
    double radius;

public:
    Circle(double r, double x, double y, double c):Figure(x, y, c),radius(r){
    }

    void draw() const override {
        cout << "Circle " << radius << "\ncenter: " << center
        << "\ncolour: " << colour << "\n";
    }
};

class Square:public Figure{
private:
    double side;

public:
    Square(double s, double x, double y, double c):Figure(x, y, c),side(s){
    }

    void draw() const override {
        cout << "Square: " << side << "\ncenter: " << center
             << "\ncolour: " << colour << "\n";
    }
};

int main() {
    /* vector<unique_ptr<Figure>> figures;
    string s;
    while(getline(cin, s)) {
        if (s == "circle") {
            figures.emplace_back(new Circle(10.0, 0.0, 0.0, 1));
        } else if (s == "square") {
            figures.emplace_back(new Square(1.,0.,0.,2););
        }
    }
    //for (Figure* figure: figures) {
    //    figure->draw();
    //}

    //for (Figure* figure : figures) {
    //    delete figure;
    //}

    for (const auto& figure : figures) {
        figure->draw();
    }

	ZOOOOOOOO	*/

#include <iostream>
#include <memory>
#include <string>
#include <vector>

using namespace std;

struct Point{
    double x;
    double y;

    Point(double first, double second) {
        x = first;
        y = second;
    }
};

ostream&operator<<(ostream& out, Point p) {
    out << p.x << " " << p.y;
    return out;
}

class Figure{
protected:
    Point center;
    int colour;

public:
    Figure(double x, double y, int c):center(x, y), colour(c) {
    }

    virtual void draw() const = 0;
};

class Circle:public Figure{
private:
    double radius;

public:
    Circle(double r, double x, double y, double c):Figure(x, y, c),radius(r){
    }

    void draw() const override {
        cout << "Circle " << radius << "\ncenter: " << center
        << "\ncolour: " << colour << "\n";
    }
};

class Square:public Figure{
private:
    double side;

public:
    Square(double s, double x, double y, double c):Figure(x, y, c),side(s){
    }

    void draw() const override {
        cout << "Square: " << side << "\ncenter: " << center
             << "\ncolour: " << colour << "\n";
    }
};

int main() {
    vector<unique_ptr<Figure>> figures;
    string s;
    while(getline(cin, s)) {
        if (s == "circle") {
            figures.emplace_back(new Circle(10.0, 0.0, 0.0, 1));
        } else if (s == "square") {
            figures.emplace_back(new Square(1.,0.,0.,2););
        }
    }
    /*for (Figure* figure: figures) {
        figure->draw();
    }

    for (Figure* figure : figures) {
        delete figure;
    }*/

    for (const auto& figure : figures) {
        figure->draw();
    }
// хз для чего
}

**********************
#include <iostream>
#include <memory>
#include <string>

using namespace std;

class C{
    int x = 42;
    double e = 2.71828;
    string s = "Hello, world!";

public:
    C() {cout << "C()\n";}
    C(const C&) {cout << "C(const C&\n";}
    void operator=(const C&){cout << "operator=(const C&\n";}
    ~C(){cout <<"~C()\n";}
};

int main() {
    //unsigned char buf[1024];
    auto *buf = new unsigned char[1024];
    {
        C c;
    }
    {
        unique_ptr<C> c(new C);
    }
    {
        // placement new
        new(buf) C;
        C* ptr = reinterpret_cast<C*>(buf);
        ptr->~C();
    }
    delete [] buf;
}
}
