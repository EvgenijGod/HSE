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

    void Print(const char * s) const {
        fprintf(f, "%s", s);
    }

    ~File() {
        fclose(f);
    }
};

int main() {
    try {
        File f("dir/output.txt");
        f.Print("Hello, world");
    } catch (const CannotOpenFile&) {
        cout << "Cannot open file\n";
    }
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

