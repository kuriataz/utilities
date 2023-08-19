#pragma once

#include <cstdio>
#include <utility>

template <typename T>
struct Array
{
    // using i64 = std::int64;

    private:

    int size = 0;
    int capacity = 0;
    T *array = nullptr;

    public:

    Array()
    {
        array = nullptr;
    }

    // Array(Array const& old): array(old)
    // {
    //     size = old.size;
    //     capacity = old.capacity;
    // }

    Array(Array const &old)
    {
        array = new T[old.capacity];
        size = old.size;
        capacity = old.capacity;
        for (int i = 0; i != old.size; i++)
        {
            array[i] = old.array[i];
        }
    }

    // Array(Array&& old): array(std::move(old))
    // {
    //     size = old.size;
    //     capacity = old.capacity;
    // }

    Array(Array&& old)
    {
        array = new T[old.capacity];
        size = old.size;
        capacity = old.capacity;
        for (int i = 0; i != old.size; i++)
        {
            array[i] = old.array[i];
        }
        delete[] old.array;
    }

    ~Array()
    {
        delete[] array;
    }

    T& operator [] (int index)
    {
        if (index >= size || index < 0)
        {
            // error handling
        }
        return array[index];
    }

    int get_size()
    {
        return size;
    }

    int get_capacity()
    {
        return capacity;
    }

    T& push_back(T&& new_element)
    {
        if (array == nullptr)
        {
            array = new T[64];
            size = 0;
            capacity = 64;
        }
        // no enough space
        if (size == capacity)
        {
            T *new_array = new T[capacity * 2];
            for (int i = 0; i != size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity *= 2;
        }
        array[size] = std::move(new_element);
        size++;

        return array;
    }

    T& push_back(T const& new_element)
    {
        if (array == nullptr)
        {
            array = new T[64];
            size = 0;
            capacity = 64;
        }
        // no enough space
        if (size == capacity)
        {
            T *new_array = new T[capacity * 2];
            for (int i = 0; i != size; i++)
            {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity *= 2;
        }
        array[size] = new_element;
        size++;

        return *array;
    }
    T* begin()
    {
        return array;
    }
    T* end()
    {
        return &array[size];
    }

};