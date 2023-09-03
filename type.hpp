#include <iostream>

template <typename T>
struct rem_ref
{
    using type = T;
};

template <typename T>
struct rem_ref<T&>
{
    using type = T;
};


struct A
{
    A() = default;
    A(A const&)
    {
        std::cout << "copied\n";
    }
};

template<typename T>
void fn(T a)
{

}

int main()
{
    A a;
    fn<A const&>(a);
    return 0;
}