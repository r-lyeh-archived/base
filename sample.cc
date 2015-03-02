#include <iostream>
#include <string>
#include "base91.hpp"

int main() {
    std::string encoded_64 = base64::encode("Hello world from BASE64! \x1\x2");
    std::string decoded_64 = base64::decode(encoded_64);
    std::cout<< decoded_64 << " <-> " << encoded_64 << std::endl;

    std::string encoded_91 = base91::encode("Hello world from BASE91! \x1\x2");
    std::string decoded_91 = base91::decode(encoded_91);
    std::cout<< decoded_91 << " <-> " << encoded_91 << std::endl;
}
