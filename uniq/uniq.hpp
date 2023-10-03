#pragma once

#include <cstdio>
#include <utility>
#include <iterator.hpp>

// find_uniq
// takes only unique elements from given collection
//
// Example:
// Given range
// 1 2 2 3 1 -> 1 2 3 1
//
// Parameters:
// begin - pointer to the first element from the collection that is modified
//   end - is a pointer to the one after the last element from the collection that is modified
//
// Return:
// returns pointer to one after the last element in modified collection
//
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
            ++result;
            *result = std::move(*begin);
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
        return end;
    }
    T *result = begin;
    T* j = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin == *j && *begin != *result)
        {
            ++result;
            *result = std::move(*begin);
        }
        ++begin;
        ++j;
    }
    return result;
}

template <typename T>
T find_duplicate(T begin, T end)
{
    if (begin == end)
    {
        return end;
    }
    T result = begin;
    T j = begin;
    ++begin;
    while (begin != end)
    {
        if (*begin == *j && *begin != *result)
        {
            ++result;
            *result = std::move(*begin);
        }
        ++begin;
        ++j;
    }
    return result;
}
