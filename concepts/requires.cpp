#include <iostream>

template <typename T>
concept has_type_member = requires
{
    typename T::type;
};

struct S1
{
};
struct S2
{
    using type = int;
};

int main()
{

    return 0;
}