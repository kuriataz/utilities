#pragma once

#include <cstdio>
#include <utility>
#include <iterator.hpp>

// find_uniq is a function that takes only unique elements from given collection
// example: 1 2 2 3 1 -> 1 2 3 1
// it returns pointer to one after the last element in modified collection
// begin is a pointer to the first element from the collection that is modified
// end is a pointer to the one after the last element from the collection that is modified
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
T find_uniq(T begin, T end)
{
    if (begin == end)
    {
        return begin;
    }
    T result = begin;
    while (++begin != end)
    {
        if (*result != *begin)
        {
            *(++result) = std::move(*begin);
        }
    }
    return ++result;
}

// find_duplicate is a function that takes only duplicated elements from given collection
// example: 1 2 2 3 3 3 1 -> 2 3
// it returns pointer to one after the last element in modified collection
// begin is a pointer to the first element from the collection that is modified
// end is a pointer to the one after the last element from the collection that is modified
template <typename T>
T *find_duplicate(T *begin, T *end)
{
    if (begin == end)
    {
        return nullptr;
    }
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

template <typename T>
T find_duplicate(T begin, T end)
{
    if (begin == end)
    {
        return begin;
    }
    T origin_beg = begin;
    T result = begin;
    T pre_begin = begin;
    while (++begin != end)
    {
        if (*begin == *pre_begin)
        {
            *(result) = std::move(*begin);
            ++result;
        }
            pre_begin = begin;
    }
    result = find_uniq(origin_beg, result);
    return result;
}
