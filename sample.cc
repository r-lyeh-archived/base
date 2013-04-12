#include <iostream>
#include "base91x.hpp"

int main( int argc, const char **argv )
{
    std::string encoded = base91x::encode("hello world \x1\n");
    std::string decoded = base91x::decode(encoded);

    std::cout << decoded;
    return 0;
}
