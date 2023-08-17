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