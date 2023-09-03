#include <iostream>

template <typename T>
struct rem_ref
{
    using type = T;
};

template <typename T>
struct rem_ref<T&>
{
    // using type = T;
};


template<typename T>
struct A
{
    A() = default;
    A(A const&)
    {
        std::cout << "copied\n";
    }

    A(T* begin, T const* end) {
        std::cout << "pooter\n";
    }

    template<typename Integer, typename SFINAE = std::enable_if_t<std::is_integral_v<Integer>>>
    A(T* begin, Integer size) {
        std::cout << "integer\n" << __PRETTY_FUNCTION__ << '\n';
    }
};

template<typename T>
void fn(typename rem_ref<T>::type a)
{

}

struct Vector_Reg {
    int width = 4;
};

struct Non_Vector_Reg {};

template<typename T>
struct Is_Vector_Register {
    static constexpr bool value = false;
};

template<>
struct Is_Vector_Register<Vector_Reg> {
    static constexpr bool value = true;
};

template<typename Reg>
struct Instr {
    Reg const* lhs;
    Reg const* rhs;
};

template<bool Cond, typename T>
struct Enable_If {
    using type = T;
};

template<typename T>
struct Enable_If<false, T> {

};

template<typename Reg>
typename Enable_If<Is_Vector_Register<Reg>::value, Instr<Reg>>::type
create_add_instr(Reg const* reg1, Reg const* reg2) {
    std::cout << "vector\n";
    if(reg1->width > 1) {
        // ...
    }
    return Instr<Reg>{reg1, reg2};
}

template<typename Reg>
typename Enable_If<!Is_Vector_Register<Reg>::value, Instr<Reg>>::type
create_add_instr(Reg const* reg1, Reg const* reg2) {
    std::cout << "non-vector\n";
    return Instr<Reg>{reg1, reg2};
}

template<typename... T>
struct variadic {};


template<typename... Ts>
int add(Ts... values) {
    std::cout << sizeof...(values) << " " << sizeof...(Ts) << "\n";
    return (... + values);
}

template<typename T>
int sub(T v) {
  return v;
}

template<typename T1, typename... Ts>
int sub(T1 v1, Ts... values) {
    return v1 - sub(values...);
}

// std::move
// static_cast<std::remove_reference<decltype(x)>&&>(x);
// std::forward

int main()
{
    std::cout << "return of add: " << add(5, 3, 1, 7, 20, 10) << '\n';
    std::cout << "return of sub: " << sub(5, 3, 1, 7, 20, 10) << '\n';

    Vector_Reg reg1;
    Vector_Reg reg2;
    create_add_instr(&reg1, &reg2);
    Non_Vector_Reg nreg1;
    Non_Vector_Reg nreg2;
    create_add_instr(&nreg1, &nreg2);

    A<int> a;
    // fn<A&>(a);
    int* c;
    int* b;
    A<int> a2(c, b);
    return 0;
}