#pragma once

#include <string>

template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}