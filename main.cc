#include "fmt/format.h"
#include "fmt/color.h"
#include <iostream>
int main() {
    fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,"Hello, {}!\n", "world");
    std::string s = fmt::format("{} is {}", "abra", 12);
    std::cout << s << std::endl;
    return 0;
}
