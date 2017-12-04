#include "aoc04_input.hpp"
#include "assert_eq.hpp"

#include <range/v3/all.hpp>

using namespace ranges;

template<typename T>
auto is_unique(T x) {
    auto sorted = std::move(x) | action::sort;
    return adjacent_find(sorted) == end(sorted);
}

template<typename T>
auto count_unique(T&& x) {
    std::vector<std::vector<std::string>> r = x
        | view::filter([](auto x) {
            return is_unique(x);
        });

    return size(r);
}

template<typename T>
auto count_unique_anagrams(T&& x) {
    std::vector<std::vector<std::string>> r = x
        | view::filter([](auto x) {
            for_each(x, [&](auto&& y) {
                y = std::move(y) | action::sort;
            });
            return is_unique(x);
        });

    return size(r);
}

int main()
{
    assert_eq(count_unique(input), 386u);
    assert_eq(count_unique_anagrams(input), 208u);

    return 0;
}
