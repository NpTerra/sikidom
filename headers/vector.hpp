#pragma once
#include <stddef.h>
#include <algorithm>

#define __IT_OUTOFRANGE     "Iterátor túlindexelés!"
#define __VEC_OUTOFRANGE    "Vector túlindexelés!"
#define __VEC_EMPTY         "Üres Vector-nak nem lehet kikérni elemét!"

template<typename T>
class Vector {
    private:
        T* _arr;
        size_t _cap;
        size_t _size;
    public:
        Vector(size_t size) : _cap(size), _size(0), _arr(new T[size]) {}
        Vector() : Vector(0) {}
        ~Vector() { delete[] _arr; }

        size_t size() const { return _size; }

        void clear() { _size = 0; }
        void resize(size_t size) {
            _cap = size;
            T* temp = new T[_cap];
            _size = std::min(_size, _cap);
            for(size_t i = 0; i < _size; i++)
            {
                temp[i] = _arr[i];
            }
            delete[] _arr;
            _arr = temp;
        }

        T* begin() const { return _arr; }
        T* end() const { return _arr+_size; }

        void push_back(T& n) {
            if(_size == _cap)
                resize(_cap*2);

            _arr[_size++] = n;
        }

        T& back() const {
            if(_size == 0)
                throw std::out_of_range(__VEC_EMPTY);
            
            return _arr[_size-1];
        }

        T& operator[](size_t index) const {
            if(index >= _size)
                throw std::out_of_range(__VEC_OUTOFRANGE);

            return _arr[index];
        }
};

#undef __IT_OUTOFRANGE
#undef __VEC_OUTOFRANGE
#undef __VEC_EMPTY