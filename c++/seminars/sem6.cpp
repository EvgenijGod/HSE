**********************************************************************************************

			СЕМИНАР 6 (14.02.2019)

**********************************************************************************************

В классе по дефолту поля приватные, в структуре - публичные. Структуру лучше использовать для обычного хранения связанных данных.

explicit

vector.emplace_back() // uses move-semantics


#include <iostream>
#include <string>

using namespace std;

class MyClass {
public:
    MyClass() = default; // default constructor

    MyClass(const string& data): data_(data) {}

    MyClass(const MyClass& other) {
        data_ = other.GetData();
    }

    MyClass&operator=(const MyClass& other) {
        data_ = other.GetData();
        return *this;
    }

    ~MyClass() = default;

    const string& GetData() const { // const left - returns const obj; const right - doesn't change data
        return data_;
    }

    void SetData(const string& other) {
        data_ = other;
    }
private:
    string data_;

};

int main() {
    MyClass cl("Hello");

    cout << cl.GetData() << endl;
    cl.SetData("World");
    cout << cl.GetData() << endl;

    MyClass a("Create");
    MyClass b(a);
    MyClass c;
    c = b;

    cout << a.GetData() << " " << b.GetData() << " " << c.GetData() << endl;
}


*******************************************************************************************

namespace

#include <iostream>
//#include <bits/valarray_after.h>

namespace my_space {
    template<class T>
    class MyClass {
    public:
        //template<class T>
                class MyIterator {
                public:
                    using value_type = T;
                };
    };
}

int main() {
    my_space::MyClass<int> cl;
    my_space::MyClass<int>::MyIterator it;
    my_space::MyClass<int>::MyIterator::it::value_type x = 2;
}

*********************************************************************************************

static variables


