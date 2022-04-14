#include "Vector.h"

Vector::Vector(size_t size) : Array(size) {
    _capacity = size;
}

Vector::Vector(const Vector &other) : Array(other._capacity) {
    _size = other._size;
    _capacity = other._capacity;
}

Vector &Vector::operator=(const Vector &other) {
    if(this == &other) {
        return *this;
    }
    _size = other.get_size();
    _capacity = other._capacity;
    delete[] _data;
    _data = new int[_capacity];
    for (int i = 0; i < _size; ++i) {
        _data[i] = other[i];
    }
    return *this;
}

void Vector::pushback(int val) {
    if (_size == _capacity){
        _capacity *= 2;
        int *tmp = new int[_capacity];
        for (int i = 0; i < _size; ++i) {
            tmp[i] = _data[i];
        }
        tmp[_size++] = val;
        delete[] _data;
        _data = tmp;
    }
    else{
        _data[_size++] = val;
    }
}

void Vector::pop_back() {
    _size--;
}

int &Vector::front() {
    return _data[0];
}

const int &Vector::front() const {
    return _data[0];
}

int &Vector::back() {
    return _data[_size - 1];
}

const int &Vector::back() const {
    return _data[_size - 1];
}

int &Vector::at(size_t ind) {
    if (ind >= _size) {
        throw std::out_of_range("Array bound exception");
    }
    return _data[ind];
}

const int &Vector::at(size_t ind) const {
    if (ind >= _size) {
        throw std::out_of_range("Array bound exception");
    }
    return _data[ind];
}

void Vector::insert(size_t ind, int val) {
    if (_size == _capacity){
        _capacity *= 2;
        int *tmp = new int[_capacity];
        for (int i = 0; i < _size; ++i) {
            tmp[i] = _data[i];
        }
        delete[] _data;
        _data=tmp;
    }
    for (int i = _size; i > ind; --i) {
        _data[i] = _data[i-1];
    }
    _size++;
    _data[ind] = val;
}



