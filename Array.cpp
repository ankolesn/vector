#include "Array.h"
#include <iostream>
Array::Array(size_t size) {
    _size = size;
    _data = new int[_size];
}

Array::~Array() {
    delete[] _data;
    _size = 0;
}

int Array::get(size_t ind) const {
    return _data[ind];
}

void Array::set(size_t ind, int val) {
    _data[ind] = val;
}

int &Array::operator[](size_t ind) {
    return _data[ind];
}

int Array::operator[](size_t ind) const {
    return _data[ind];
}

size_t Array::get_size() const {
    return _size;
}

Array::Array(const Array &other) {
    _size = other.get_size();
    _data = new int[_size];
    for (int i = 0; i < _size; ++i) {
        _data[i] = other.get(i);
    }
    std::cout << "copy" << std::endl;
}

Array& Array::operator=(const Array &other) {
    if (this == &other) {
        return *this;
    }
    delete[] _data;
    _size = other.get_size();
    _data = new int[_size];
    for (int i = 0; i < _size; ++i) {
        _data[i] = other.get(i);
    }
    return *this;
}

Array Array::operator+(const Array &other) const{
    Array res(*this);
    for (int i = 0; i < _size; ++i) {
        res[i] += other[i];
    }
    return std::move(res);
}



Array::Array(Array &&other) noexcept {
    _size = other._size;
    _data = other._data;
    other._data = nullptr;
    std::cout << "moveC" << std::endl;
}

Array &Array::operator=(Array &&other) noexcept {
    if (this == &other) {
        return *this;
    }
    delete[] _data;
    _size = other.get_size();
    _data = other._data;
    other._data = nullptr;
    other._size = 0;
    std::cout << "moveA" << std::endl;
    return *this;

}



