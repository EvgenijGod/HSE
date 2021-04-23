#include <cstddef>
#include <iostream>
#include <memory>

using namespace std;


class DefaultDeleter {
private:
    int counter = 0;

public:
    template <typename T>
    void operator()(T* ptr) {
        ++counter;
        delete ptr;
    }
};

template<typename T, typename Deleter>
class UniquePtr {
private:
    T *unique_ptr = nullptr;

public:
    UniquePtr() {
        unique_ptr = nullptr;
    }

    UniquePtr(T *init) : unique_ptr(init) {
    }

    UniquePtr(const UniquePtr &) = delete;

    UniquePtr(UniquePtr &&other) : unique_ptr(other.unique_ptr) {
        other.unique_ptr = nullptr;
    }

    UniquePtr& operator=(nullptr_t null_ptr) {
        delete unique_ptr;
        unique_ptr = nullptr;
        return *this;
    }

    T* release() {

    }

    void reset(T* kptr) {

    }

    ~UniquePtr() {
        delete unique_ptr;
    }

};
*****************************************************************************

#include <iostream>
#include <memory>

using namespace std;

template <typename T>
class Optional {
private:
    bool defined = false;
    alignas(T) unsigned char buf[sizeof(T)];

public:
    Optional(const T& elem) {
        new (buf) T(elem);
        defined= true;
    }

    Optional(T&& elem) {
        new (buf) T(std::move(elem));
        defined = true;
    }

    ~Optional() {
        if (defined) {
            reinterpret_cast<T*>(buf)->~T();
        }
    }
};

*********************************************************************

#include <iostream>
#include <memory>

using namespace std;

template<typename T>
struct VectorBase {
    T *base = nullptr;
    size_t capacity = 0;

    VectorBase() = default;

    VectorBase(size_t n) {
        base = reinterpret_cast<T *>(new char[n * sizeof(T)]);
        capacity = n;
    }

    ~VectorBase() {
        delete[] base;
    }
};

template<typename T>
class Vector {
private:
    VectorBase<T> buffer;
    /*T *buffer = nullptr;*/ // address
    size_t sz = 0;     // number of ppl
    /*size_t capacity = 0;*/ // number of flats

public:
    Vector() = default;

    Vector(size_t n, const T &elem) : buffer(n) {
        uninitialized_fill_n(buffer.base, n, elem);
        /*buffer = reinterpret_cast<T*>(new char[n * sizeof(T)]);
        size_t i;
        try {
            for (i = 0; i != n; ++i) {
                new (buffer + i) T(elem);
            }
        } catch (...) {
            for (size_t j = 0; j != i; ++j) {
                buffer[j].~T();
            }
            // delete [] buffer;
            throw;
        }*/
        sz = n;
    }

    Vector(Vector &other) {
        unique_ptr<int> tmp_ptr(buffer);
        tmp_ptr.release();
        buffer = other.buffer;
        //capacity = other.capacity;
    }

    Vector &operator=(Vector &other) {
        other.swap(*this);
        return *this;
    }

    void swap(Vector &other) {
        //std::swap(capacity, other.capacity);
        std::swap(buffer, other.buffer);
    }

    void push_back(const int num) {

    }

    void pop_back() {

    }

    size_t size() const {
        return sz;
    }

    size_t capacity() const {
        return buffer.base.capacity;
    }

    T &operator[](size_t index) {
        return buffer.base[index];
    }

    ~Vector() {
        for (size_t i = 0; i != sz; ++i) {
            buffer[i].~T();
        }
        // delete[] buffer;
    }
};
