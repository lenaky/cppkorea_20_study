#include <iostream>
#include <range/v3/all.hpp>

int main()
{
    auto pairs =
        ranges::view::zip_with([](int i, char c) { return std::make_pair(i, c); },
                               ranges::view::ints(0), "ranges");

    ranges::for_each(pairs, [](std::pair<int, char> p) {
        std::cout << "p.first = " << p.first << "  p.second " << p.second << std::endl;
    });

    auto total = ranges::accumulate(
        ranges::view::ints(100, 1000) |
            ranges::view::transform([](int n) { return n * n; }) |
            ranges::view::take(100),
        0);

    std::cout << "total : " << total << std::endl;
    return 0;
}