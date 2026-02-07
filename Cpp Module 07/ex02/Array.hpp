#pragma once

#include <exception> 

template <typename T>
class Array
{
    private:
        T* data;
        unsigned int _size;
    public:
        Array() : data(NULL), _size(0) {}

        Array(unsigned int n) : data(NULL), _size(n)
        {
            if (n > 0)
                data = new T[n]();
        }
        Array(const Array& obj) : data(NULL), _size(obj._size)
        {
            if(_size > 0)
            {
                data = new T[_size];
                for(unsigned int i = 0; i < _size; i++)
                    data[i] = obj.data[i];
            }
        }
        Array& operator=(const Array& obj)
        {
            if(this != &obj)
            {
                if(data)
                {
                    delete[] data;
                    data = NULL;
                }
                _size = obj._size;
                if(_size > 0)
                {
                    data = new T[_size];
                    for(unsigned int i = 0; i < _size; i++)
                        data[i] = obj.data[i];
                }
            }
            return *this;
        }
        ~Array()
        {
            if(data)
                delete[] data;
        }
        T& operator[](unsigned int i)
        {
            if(i >= _size)
                throw std::out_of_range(" index is out of bounds");
            return data[i];
        }
        const T& operator[](unsigned int i) const
        {
            if(i >= _size)
                throw std::out_of_range(" index is out of bounds");
            return data[i];
        }
        unsigned int size() const
        {
            return _size;
        }
};