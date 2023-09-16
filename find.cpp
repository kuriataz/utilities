#include <iostream>
#include <cstdlib>
#include <vector>

#include "./core/array.hpp"
#include "./core/iterator.hpp"

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
            std::cout << "HERE\n";
        if (*result != *begin)
        {
            *(++result) = std::move(*begin);
        }
    }
    return ++result;
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

int main(int argc, char **argv)
{
    Array<int> array;
    array.push_back(3);
    array.push_back(3);
    array.push_back(1);
    array.push_back(8);
    array.push_back(4);
    array.push_back(4);
    array.push_back(5);
    array.push_back(2);
    array.push_back(2);
    array.push_back(1);


    iterator<int> begin = array.begin();
    iterator<int> begin2 = array.begin();
    iterator<int> end = array.end();

    std::cout << *begin << " *begin\n";
    std::cout << *end << " *end\n";
    end = find_duplicate(begin, end);
    std::cout << *end << " *end po raz drugi\n";

    for ( ; begin != end; ++begin)
    {
        std::cout << *begin << " - main\n";
    }

    return 0;
}