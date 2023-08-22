#pragma once

#include <cstdio>
#include <utility>

using i64 = std::int64_t;
template <typename T>
struct Array
{

    private:

    int size = 0;
    int capacity = 0;
    T *storage = nullptr;

    T* alloc(i64 capacity) {
        return reinterpret_cast<T*>(malloc(sizeof(T) * capacity));
    }

    void dealloc(T* ptr, [[maybe_unused]] i64 capacity) {
        free(ptr);
    }

    void ensure_capacity(i64 const required_capacity) {
        if(capacity < required_capacity) {
            i64 new_capacity = 64;
            while(new_capacity < required_capacity) {
                new_capacity *= 2;
            }

            T *const new_storage = alloc(new_capacity);
            for (int i = 0; i != size; i++)
            {
                ::new (new_storage + i) T(std::move(storage[i]));
                storage[i].~T();
            }

            dealloc(storage, capacity);
            storage = new_storage;
            capacity = new_capacity;
        }
    }

    public:

    Array() = default;

    // Array(Array const& old): storage(old)
    // {
    //     size = old.size;
    //     capacity = old.capacity;
    // }

    Array(Array const &old)
    {
        storage = alloc(old.capacity);
        size = old.size;
        capacity = old.capacity;
        for (int i = 0; i != old.size; i++)
        {
            ::new (storage + i) T(old.storage[i]);
        }
    }

    // Array(Array&& old): storage(std::move(old))
    // {
    //     size = old.size;
    //     capacity = old.capacity;
    // }

    Array(Array&& old)
    {
        size = old.size;
        capacity = old.capacity;
        storage = old.storage;

        old.size = 0;
        old.capacity = 0;
        old.storage = nullptr;
    }

    ~Array()
    {
        // TODO: Call all destructors.
        dealloc(storage, capacity);
    }

    T& operator[] (int index)
    {
        return storage[index];
    }
    Array& operator= (const Array&) = default;

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
        ensure_capacity(size + 1);
        ::new (storage + size) T(std::move(new_element));
        size++;
        return *storage;
    }

    T& push_back(T const& new_element)
    {
        ensure_capacity(size + 1);
        ::new (storage + size) T(new_element);
        size++;
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
        return storage + size;
    }

    bool empty()
    {
        if (size == 0)
        {
            return true;
        }
        return false;
    }

};