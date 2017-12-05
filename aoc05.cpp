#include "assert_eq.hpp"
#include "aoc05_input.hpp"

#include <vector>

template<class Op>
int num_jumps(std::vector<int> x, Op op) {
    int num = 0;
    auto i = begin(x);
    while (i >= begin(x) && i < end(x)) {
        auto& current = *i;
        i = i + current;
        current = op(current);
        num++;
    }
    return num;
}

template<size_t size>
int num_jumps(const int (&x)[size]) {
    return num_jumps(std::vector<int>{x, x + size},
                     [](int x) { return x + 1; } );
}

template<size_t size>
int num_jumps_decrease(const int (&x)[size]) {
    return num_jumps(std::vector<int>{x, x + size},
                     [](int x) { return x >= 3 ? x - 1 : x + 1; } );
}

int main()
{
    const int test01[] = {0, 3, 0, 1, -3};

    assert_eq(num_jumps(test01), 5);
    assert_eq(num_jumps(aoc05_input), 360603);

    assert_eq(num_jumps_decrease(test01), 10);
    assert_eq(num_jumps_decrease(aoc05_input), 25347697);

    return 0;
}
