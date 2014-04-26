#include <iostream>
#include "base91x.hpp"

int main() {
    std::string encoded = base91x::encode("hello world from base91x! \x1\x2");
    std::string decoded = base91x::decode(encoded);

    std::cout << encoded << " <-> " << decoded << std::endl;
}
