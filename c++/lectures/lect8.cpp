#include <iostream>


using namespace std;


class Date {
private:
    int day;
    int month;
    int year;

public:
    int GetDay() const {
        return day;
    }

    int GetMonth() const {
        return month;
    }

    int GetYear() const {
        return year;
    }

    Date(int d, int m, int y) {
        if (d <= 0 || d >= 32) {
            throw "Invalid date";
        }
        day = d;
        month = m;
        year = y;
    }

    //void Increase() {
    Date& operator++() {
        if (day < 31)
            ++day;
        else if (month < 12) {
            day = 1;
            ++month;
        } else {
            day = 1;
            month = 1;
            ++year;
        }
        return *this;
    }
    int DaysBetween (const Date& d2) const {
        //return d2.GetDay() - GetDay(); // this->Getday() == GetDay()
        return d2.day - day;
    }
    /*int operator- (const Date& d2) const {
        //return d2.GetDay() - GetDay(); // this->Getday() == GetDay()
        return d2.day - day;
    }*/
};

int DaysBetween (const Date& d1, const Date& d2) {
    return d2.GetDay() - d1.GetDay(); // incorrect
}

int operator- (const Date& d1, const Date& d2) {
    return d2.GetDay() - d1.GetDay(); // incorrect
}

int main() {
    Date d = {31, 8, 2019}; // if const then member-functions (without const) won't compile
    //++d.day; // day is private
    //++(++d);

    Date d2 = {15, 8, 2019};
    cout << DaysBetween(d, d2) << "\n";
    cout << d.DaysBetween(d2) << "\n";
    cout << d - d2 << "\n";
    cout << d.GetDay() << " "
         << d.GetMonth() << " "
         << d.GetYear() << "\n";

}

*******************************************

#include <iostream>
#include <cmath>

using namespace std;

class Complex {
private:
    double re, im;

public:
    Complex(double x, double y) {
        re = x;
        im = y;
    }

    double Re() const {
        return re;
    }

    double &Re() {  // compiler tries to call non-constant function if possible
        return re;
    }

    double Im() const {
        return im;
    }

    double &Im() {
        return im;
    }

    double Norm() const {
        return std::sqrt(re * re + im * im);
    }
    Complex& operator += (const Complex& z2) {
        re += z2.re;
        im += z2.im;
        return *this;
    }
};

Complex& operator -= (Complex& z1, const Complex& z2) {
    z1.Re() += z2.re;
    z1.Im() += z2.im;
    return z1;
}

Complex operator + (const Complex& z1, const Complex& z2) {
    return {z1.Re() + z2.Re(),
            z1.Im() + z2.Im()};
}

ostream &operator<<(
        ostream &out,
        const Complex &z
) {
    return out << "(" << z.Re() << ", " << z.Im() << ")";
}

int main() {
    const Complex z{3.0, -4.0};
    Complex z2{2, 1};
    //z.Re() = 3.1415;
    cout << z << "\n";
    cout << z + z2 << "\n";
    z -= z2;
    cout << z.Re() << " " << z.Im() << "\n";
    cout << z.Norm() << "\n";
}

**************************************************

#include <iostream>

class C {
public:
    void f(int x) const; //{
    //    std::cout << "Inner f(int) called\n";
    //}
};

void C::f(int x) const {
    std::cout << "Inner f(int) called\n";
}

void g (const C& obj, int x) {
    std::cout << "Outer g(const C&, int) called\n";
}

int main() {
    C c;
    c.f(42);
    g(c, 42);
}

**************************************************

#include <iostream>

class C {
public:
    //void f(int x) const; //{
    //    std::cout << "Inner f(int) called\n";
    //}
    C() {
        std::cout << "Constructor called\n";
    }
    ~C() {
        std::cout << "Destructor called\n";
    }
};

/*void C::f(int x) const {
    std::cout << "Inner f(int) called\n";
}*/

void g (const C& obj, int x) {
    std::cout << "Outer g(const C&, int) called\n";
}

int main() {
    C c;
    //c.f(42);
    //g(c, 42);
}
