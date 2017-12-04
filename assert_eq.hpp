#pragma once

#include <iostream>

#define assert_eq(a, b) do { \
    auto r1_ = (a); \
    auto r2_ = (b); \
    if (!(r1_ == r2_)) { \
        std::cout << __FUNCTION__ << ":" << __LINE__ \
                  << " assert_eq(" << r1_ << ", " << r2_ << ") " << #a << ", " << #b \
                  << std::endl; } \
} while(false)
