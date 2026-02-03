#pragma once

#include <iostream>

template <typename T, typename F> void iter(T* array, const int len, F fun)
{
    for (int i = 0; i < len; i++)
    {
        fun(array[i]);
    }
}