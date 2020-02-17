#include <iostream>

template <typename T>
concept has_bool_value_member = requires
{
    {
        T::value
    }
    ->std::convertible_to<bool>;
};

int main()
{
    return 0;
}