#include "magic_enum.hpp"
#include <iostream>

enum class Color {
    Red,
    Green,
    Blue
};

// test __PRETTY_FUNCTION__
void test_PRETTY_FUNCTION() {
    std::cout << _enum_type_name<Color>() << '\n'
              << _enum_value_name<static_cast<Color>(0)>() << '\n' 
              << _enum_value_name<static_cast<Color>(1)>() << '\n'
              << _enum_value_name<static_cast<Color>(2)>() << '\n';
}

// test search for max enum number
void test_search() {
    std::cout << _enum_range<Color>() << '\n';
}

// test enum to string
void test_enum2string() {
    std::cout << dump_enum(Color::Blue) << '\n';
}

void test_string2num() {
    auto ret = parse_enum<Color>("Blue");
    std::cout << static_cast<int>(ret) << '\n';
}

int main() {
    test_PRETTY_FUNCTION();
    test_search();
    test_enum2string();
    test_string2num();
    return 0;
}