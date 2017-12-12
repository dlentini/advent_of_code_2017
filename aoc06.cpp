#include "assert_eq.hpp"

#include <range/v3/all.hpp>
#include <vector>
#include <map>

using namespace ranges;

void redistribute(std::vector<int>& x) {
    auto i = max_element(x);
    auto num = *i;
    *i = 0;
    while (num-- != 0) {
        i++;
        if (i == x.end()) i = x.begin();
        *i += 1;
    }
}

auto memory_relocations(std::vector<int> x) {
    std::map<std::vector<int>,int> history {{x,0}};
    int loop_count = 0;
    while (true) {
        redistribute(x);
        if (history.find(x) != history.end()) break;
        history[x] = loop_count;
        loop_count++;
    }
    return std::make_pair(history.size(), loop_count - history[x]);
}

auto num_memory_relocations(std::vector<int> x) {
    return memory_relocations(x).first;
}

auto loops_memory_relocations(std::vector<int> x) {
    return memory_relocations(x).second;
}

int main()
{
    const std::vector<int> test01 = {0, 2, 7, 0};
    const std::vector<int> test02 = {0, 5, 10, 0, 11, 14, 13, 4, 11, 8, 8, 7, 1, 4, 12, 11};

    assert_eq(num_memory_relocations(test01), 5u);
    assert_eq(num_memory_relocations(test02), 7864u);

    assert_eq(loops_memory_relocations(test01), 4);
    assert_eq(loops_memory_relocations(test02), 1695);

    return 0;
}
