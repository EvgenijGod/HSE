**********************************************************************************************

#include <iostream>
#include <memory>
using namespace std;

class C {
private:
    static int counter;
    const int id;

public:
    C(): id(++counter) {
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
    unique_ptr<C> a(new C);
    unique_ptr<C> b(new C);
    unique_ptr<C> c(new C);
    b.reset();
    a.reset();
    c.reset();
}

***********************************************************************************************

class A;

class C {
private:
    A * x;
    A * y;
public:
    C() {
        
    }
    C(const C& other) {
        x = new A(*other.x);
        try {
            y = new A(*other.y);
        } catch (...) {
            delete x;
            throw;
        }

    }
};

**********************************************************************************************

#include <iostream>
#include <stdexcept>

using namespace std;

class C {
public:
    C() {
        //throw 42;
        cout << "C()\n";
    }
    C (const C&) {
        cout << "C(const C&)\n";
    }
    ~C() {
        cout << "~C()\n";
    }
};

void foo() {
    C x;
    throw runtime_error("context");
    C y;
}

int main() {
    try {
        foo();
    } catch (const runtime_error& e){       // раскрутка стека, вызов деструктора х
        cout << e.what() << "\n";
    } catch (int x){
        cout << "Strange int exception: 42\n";
    } catch (...) {
        cout << "Other exception\n";
    }
}

*********************************************************************************************

// RAII
// Resource Acquisition Is Initialization

// Garbage collection in other languages

#include <stdio.h>
#include <iostream>

using namespace std;

struct CannotOpenFile {
};

class File {
private:
    FILE* f;

public:
    explicit File(const char* path) {
        f = fopen(path, "w");
        if (f == nullptr)
            throw CannotOpenFile();
    }

    File(const File&) = delete;

    File&operator=(const File&) = delete;

    File(File&& other) {
        f = other.f;
        other.f = nullptr;
    }

    File&operator=(File&& other) {
        swap(f, other.f);
        return *this;
    }

    void Print(const char * s) const {
        fprintf(f, "%s", s);
    }

    ~File() {
        if (f != nullptr)
            fclose(f);
    }
};

int main() {
    try {
        File f("dir/output.txt");
        f.Print("Hello, world");
        //auto f2 = f;
        //f2.Print("Goodbye\n");
    } catch (const CannotOpenFile&) {
        cout << "Cannot open file\n";
    }
}

File& open_file () {
    
}

int old_main() {
    FILE * f;
    f = fopen("output.txt", "w");
    if (f == nullptr) {
        cout << "Cannot open file\n";
        return 1;
    }
    fprintf(f, "Hello, world\n");
    fclose(f);
    return 0;
}

