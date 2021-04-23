#include <iostream>
#include <string>

using namespace std;

class Writer {
public:
    virtual void Write(const char *data, size_t len) {
        for (size_t i = 0; i != len; ++i)
            cout << *(data + i) << " ";
        cout << "\n";
        // Какой-то вывод в файл, на экран или в память
    }
};

class BufferedWriter : public Writer {
private:
    char *buffer;
    size_t buf_size_ = 0;
    size_t cur_index = 0;

public:
    BufferedWriter(size_t buf_size) {
        buffer = new char[buf_size];
        buf_size_ = buf_size;
    }

    void Write(const char *data, size_t len) override {
        for (size_t i = 0; i != len; ++i) {
            if (cur_index >= buf_size_)
                break;
            *(buffer + cur_index) = *(data + i);
            ++cur_index;
        }
        if (cur_index == buf_size_)
            Writer::Write(buffer, buf_size_);
    }

    ~BufferedWriter() {
        Writer::Write(buffer, cur_index);
        delete[] buffer;
    }
};

int main() {
    BufferedWriter w(10);
    const char *data = "hello0";
    w.Write(data, 5);
    w.Write(data, 6);
}
