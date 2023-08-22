#include <uniq.hpp>
#include <cstdio>
#include <utility>

int *uniq (int *begin, int *end)
{
    if (begin == end)
    {
        return begin;
    }
    int *result = begin;
    while (++begin != end)
    {
        if (*result != *begin)
        {
            *(++result) = std::move(*begin);
        }
    }
    return ++result;
}

int *duplicate (int *begin, int* end)
{
    if (begin == end)
    {
        return nullptr;
    }
    int *result = begin;
    while (++begin != end)
    {
        if (*begin == *(begin - 1))
        {
            *(result++) = std::move(*begin);
        }
    }
    return result;
}