#include <iostream>

using namespace std;

int main() {
    int x = 123;
    int * mem = new (&x) int; // placement new (выделяется в буфере)

    // delete not needed
}

*********************************

#include <iostream>

using namespace std;

class Base {
    Base();
    //~Base();
    virtual ~Base();
};

class Derived:public Base{
    Derived():Base();
    ~Derived();
};

int main() {
    Base *b = new Derived;
    //delete b; // ~Derived() not called if ~Base() not virtual
}

**********************************

//INTEGRAL

template <typename T>
class IntegrationMethod{
public:
    virtual void Integrate();
};

template <typename T>
class RectangleRule:public IntegrationMethod<T>{
public:
    void Integrate() override;
};

***************************************

#include <iostream>
#include <memory>

using namespace std;

/* mutex m; m.lock(); m.unlock() */

class SharedPtr{
private:
    int*data{nullptr};
    size_t *refCount{nullptr};

public:
    SharedPtr(int *init):data{init} {
        /*try {
            refCount = new size_t(1);
        } catch(...) {
            delete init;
        }*/

        unique_ptr<int> temp{init};
        refCount = new size_t(1);
        temp.release();
    }

    void Release() {
        // decrements refCount and clears data if needed;
        --*refCount;
        if (*refCount == 0) {
            delete data;
            delete refCount;
        }
    }

    ~SharedPtr() {
        Release();
    }

    SharedPtr&operator=(SharedPtr& other) {
        if (this == &other) {
            return *this;
        }
        Release();
        data = other.data;
        refCount = other.refCount;
        ++*refCount;
        return *this;
    }
};
