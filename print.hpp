#pragma once

#include <iostream>

struct printer {
    std::ostream &os_;
    bool &first_;

    template<typename T>
    void operator()(T const &t) const
    {
        if (first_) first_ = false;
        else os_ << ',';
        os_ << t;
    }
};

namespace ranges {
    template<typename... Ts>
    std::ostream &operator<<(std::ostream &os, std::tuple<Ts...> const &t)
    {
        os << '(';
        auto first = true;
        tuple_for_each(t, printer{os, first});
        os << ')';
        return os;
    }
}

#define print(rng) do { std::cout << __FUNCTION__ << ":" << __LINE__ << ": "; \
    copy(rng, ostream_iterator<>(std::cout, ",")); \
    std::cout << std::endl; }while(false)
