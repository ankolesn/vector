#ifndef ARRAY_VECTOR_H
#define ARRAY_VECTOR_H
#include "Array.h"

class Vector : public Array{
private:
    size_t _capacity;
public:
    explicit Vector(size_t size);
    ~Vector() = default;
    Vector(const Vector& other);
    Vector& operator=(const Vector& other);
    void pushback(int val);
    void pop_back();
    int& front();
    [[nodiscard]] const int& front() const;
    int& back();
    [[nodiscard]] const int& back() const;
    int& at(size_t ind);
    [[nodiscard]] const int& at(size_t ind) const;
    void insert (size_t ind, int val );


};


#endif //ARRAY_VECTOR_H
