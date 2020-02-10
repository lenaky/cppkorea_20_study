#include <iostream>
#include <range/v3/all.hpp>

int main()
{
    auto samzo = ranges::view::for_each(ranges::view::ints(1), [](int z) {
        return ranges::view::for_each(ranges::view::ints(1, z), [=](int x) {
            return ranges::view::for_each(ranges::view::ints(x, z), [=](int y) {
                return ranges::yield_if(x * x + y * y == z * z, std::make_tuple(x, y, z));
            });
        });
    });

    // 종료 조건 명시. Lazy evaluation 할때 종료조건이 존재하지 않으면 무한루프에 빠짐.
    auto quit_cond = ranges::view::take_while([](std::tuple<int, int, int> nums) {
        return std::get<0>(nums) < 100;
    });

    // Lazy evaluation
    ranges::for_each(samzo | quit_cond, [](std::tuple<int, int, int> nums) {
        std::cout << std::get<0>(nums) << ", " << std::get<1>(nums) << ", " << std::get<2>(nums) << std::endl;
    });
    return 0;
}