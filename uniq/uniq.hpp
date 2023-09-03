#pragma once

#include <cstdio>
#include <utility>

template <typename T>
T *find_uniq(T *begin, T *end)
{
    if (begin == end)
    {
        return begin;
    }
    T *result = begin;
    while (++begin != end)
    {
        if (*result != *begin)
        {
            *(++result) = std::move(*begin);
        }
    }
    return ++result;
}

template <typename T>
T *find_duplicate(T *begin, T *end)
{
    if (begin == end)
    {
        return nullptr;
    }
    T *beg = begin;
    T *result = begin;
    while (++begin != end)
    {
        if (*begin == *(begin - 1) && *begin != *(result - 1))
        {
            *(result++) = std::move(*begin);
        }
    }
    return result;
}