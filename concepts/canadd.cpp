#include <iostream>

template <typename T>
concept can_add = requires(T t, T u)
{
    t + u;
};

template <typename T, typename U>
requires can_add<T, U> auto add(T t, U u)
{
    return t + u;
};

int main()
{
    add(3, 4);

    return 0;
}