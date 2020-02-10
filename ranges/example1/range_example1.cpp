#include <iostream>
#include <vector>
#include <range/v3/all.hpp>

template <typename T>
struct _my_iota_view
{
    operator std::vector<T>()
    {
        std::vector<T> temp_v;
        temp_v.reserve(_end - _begin);

        for (; _begin != _end; _begin++)
            temp_v.emplace_back(_begin);
        return temp_v;
    }

    T _begin;
    T _end;
};

struct _my_iota_fn
{
    template <typename T>
    _my_iota_view<T> operator()(T beg, T end) const
    {
        return _my_iota_view<T>{beg, end};
    }
} my_iota;

int main()
{
    std::string s{"hello world"};
    ranges::for_each(s, [](char c) { std::cout << c << ' '; });
    std::cout << std::endl;

    std::vector<int> v1 = ranges::to<std::vector<int>>(ranges::view::iota(0, 10));

    std::vector<int> v2 = my_iota(0, 10);

    return 0;
}
