#pragma once

#include <iostream>

#define assert_eq(a, b) do { \
    if (!(a == b)) { \
        std::cout << __FUNCTION__ << ":" << __LINE__ \
                  << " assert_eq(" << a << ", " << b << ") " << #a << ", " << #b \
                  << std::endl; } \
} while(false)
