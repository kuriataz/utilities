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
    array.push_back(2);

    std::vector<int> vec;
    vec.push_back(3);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(8);
    vec.push_back(4);
    vec.push_back(4);
    vec.push_back(5);
    vec.push_back(2);
    vec.push_back(2);
    vec.push_back(2);


    // iterator<int> begin = array.begin();
    iterator<int> begin = &vec[0];
    iterator<int> begin2 = array.begin();
    iterator<int> begin3 = array.begin();
    // iterator<int> end = array.end();
    iterator<int> end = &vec[vec.size()];

    std::cout << *begin << '\n';
    std::cout << *end << '\n';
    end = find_uniq(begin, end);
    std::cout << *begin << '\n';
    for ( ; begin != end; ++begin)
    {
    std::cout << "test" << "\n";
        std::cout << *begin << " - main\n";
    }

    return 0;
}