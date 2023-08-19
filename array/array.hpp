template <typename T>
struct Array
{
    // using i64 = std::int64;

    int size = 0;
    int capacity = 0;
    T *array;

    public:

    Array()
    {
        array = nullptr;
    }

    Array(Array const& old): array(old)
    {
        size = old.size;
        capacity = old.capacity;
    }

    // Array(Array const &old)
    // {
    //     array = new T[old.capacity];
    //     size = old.size;
    //     capacity = old.capacity;
    //     for (int i = 0; i != old.size; i++)
    //     {
    //         array[i] = old.array[i];
    //     }
    // }

    Array(Array&& old): array(std::move(old))
    {
        size = old.size;
        capacity = old.capacity;
    }

    ~Array();

    T& push_back(T&&);
    T& push_back(T const& new_element)
    {
        if (size == capacity)
        {
            array[size + 1] = new_element;
        }
        else
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
    }
    T* begin();
    T* end();

};