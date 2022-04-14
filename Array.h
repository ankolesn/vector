#ifndef ARRAY_ARRAY_H
#define ARRAY_ARRAY_H


#include <cstddef>
#include <iostream>

class Array {
protected:
    int *_data;
    size_t _size;
public:
    explicit Array(size_t size);

    Array(const Array &other);

    Array(Array &&other) noexcept;

    ~Array();

    [[nodiscard]] int get(size_t ind) const;

    void set(size_t ind, int val);

    [[nodiscard]] size_t get_size() const;

    int &operator[](size_t ind);

    int operator[](size_t ind) const;

    Array &operator=(const Array &other);

    Array &operator=(Array &&other) noexcept;

    Array operator+(const Array &other) const;

};

inline std::ostream &operator<<(std::ostream &os, const Array &a) {
    for (int i = 0; i < a.get_size(); ++i) {
        os << a[i] << ' ';
    }
    return os;
}

inline std::istream &operator>>(std::istream &is, Array &a) {
    for (int i = 0; i < a.get_size(); ++i) {
        is >> a[i];
    }
    return is;
}

#endif //ARRAY_ARRAY_H
