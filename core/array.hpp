#pragma once

#include <cstdio>
#include <utility>
#include <iterator>

using i64 = std::int64_t;
template <typename T>
struct Array
{
    private:
    int _size = 0;
    int _capacity = 0;
    T *storage = nullptr;

    T* alloc(i64 capacity) {
        return reinterpret_cast<T*>(malloc(sizeof(T) * capacity));
    }

    void dealloc(T* ptr, [[maybe_unused]] i64 capacity) {
        free(ptr);
    }

    void ensure_capacity(i64 const required_capacity) {
        if(_capacity < required_capacity) {
            i64 new_capacity = 64;
            while(new_capacity < required_capacity) {
                new_capacity *= 2;
            }

            T *const new_storage = alloc(new_capacity);
            for (int i = 0; i != _size; i++)
            {
                ::new (new_storage + i) T(std::move(storage[i]));
                storage[i].~T();
            }

            dealloc(storage, _capacity);
            storage = new_storage;
            _capacity = new_capacity;
        }
    }

    public:
    Array() = default;

    Array(Array const &old)
    {
        storage = alloc(old._capacity);
        _size = old._size;
        _capacity = old._capacity;
        for (int i = 0; i != old._size; i++)
        {
            ::new (storage + i) T(old.storage[i]);
        }
    }

    Array(Array&& old)
    {
        _size = old._size;
        _capacity = old._capacity;
        storage = old.storage;

        old._size = 0;
        old._capacity = 0;
        old.storage = nullptr;
    }

    ~Array()
    {
        // TODO: Call all destructors.
        for (int i = 0; i != _size; i++)
        {
            storage[i].~T();
        }
        dealloc(storage, _capacity); // only if it is commented dict remove works
    }

    // doesn't work well
    T& operator[] (int index)
    {
        if (index < 0 || index >= _size)
        {
            // std::cerr << "out of range - from operator[]\n";
        }
        return storage[index];
    }
    Array& operator= (const Array&) = default;

    int size()
    {
        return _size;
    }

    int capacity()
    {
        return _capacity;
    }

    T& push_back(T&& new_element)
    {
        ensure_capacity(_size + 1);
        ::new (storage + _size) T(std::move(new_element));
        _size++;
        return *storage;
    }

    T& push_back(T const& new_element)
    {
        ensure_capacity(_size + 1);
        ::new (storage + _size) T(new_element);
        _size++;
        return *storage;
    }

    T& erase(int position)
    {
        storage[position].~T();
        for ( ; position != _size; ++position)
        {
            storage[position - 1] = storage[position];
        }
        storage[_size - 1].~T();
        _size--;
        return *storage;
    }

    T* data() {
        return storage;
    }

    T* begin()
    {
        return storage;
    }
    T* end()
    {
        return storage + _size;
    }

    bool empty()
    {
        return _size == 0;
    }
};
