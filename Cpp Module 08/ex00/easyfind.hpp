#pragma once

#include <stdexcept>

template <typename T>
 typename T::iterator easyfind(T& container, int val)
{
    typename T::iterator i;
    for(i = container.begin(); i != container.end(); i++)
    {
        if (*i == val)
            return i;
    }
    throw std::runtime_error("value not Found!");
}
