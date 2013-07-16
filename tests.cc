#include <cassert>
#include <iostream>
#include "base91x.hpp"

// base64 is based on code by René Nyffenegger
namespace base64
{
    static const std::string chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    static inline bool is_base64(unsigned char c) {
        return (isalnum(c) || (c == '+') || (c == '/'));
    }

    std::string encode( const std::string &text ) {
        unsigned char const* bytes_to_encode = (unsigned char const *)text.c_str();
        unsigned int in_len = (unsigned int)text.size();
        std::string ret;
        int i = 0;
        int j = 0;
        unsigned char char_array_3[3];
        unsigned char char_array_4[4];

        while (in_len--) {
            char_array_3[i++] = *(bytes_to_encode++);
            if (i == 3) {
                char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
                char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
                char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
                char_array_4[3] = char_array_3[2] & 0x3f;

                for(i = 0; (i <4) ; i++)
                    ret += chars[char_array_4[i]];
                i = 0;
            }
        }

        if (i)
        {
            for(j = i; j < 3; j++)
                char_array_3[j] = '\0';

            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (j = 0; (j < i + 1); j++)
                ret += chars[char_array_4[j]];

            while((i++ < 3))
                ret += '=';
        }

        return ret;
    }

    std::string decode( const std::string &encoded ) {
        int in_len = encoded.size();
        int i = 0;
        int j = 0;
        int in_ = 0;
        unsigned char char_array_4[4], char_array_3[3];
        std::string ret;

        while (in_len-- && ( encoded[in_] != '=') && is_base64(encoded[in_])) {
            char_array_4[i++] = encoded[in_]; in_++;
            if (i ==4) {
                for (i = 0; i <4; i++)
                    char_array_4[i] = chars.find(char_array_4[i]);

                char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
                char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
                char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

                for (i = 0; (i < 3); i++)
                    ret += char_array_3[i];
                i = 0;
            }
        }

        if (i) {
            for (j = i; j <4; j++)
                char_array_4[j] = 0;

            for (j = 0; j <4; j++)
                char_array_4[j] = chars.find(char_array_4[j]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
        }

        return ret;
    }
}

void compare( const std::string &ascii ) {

    std::string text64 = base64::encode(ascii);
    std::string text91 = base91::encode(ascii);

    assert( ascii == base64::decode( text64 ) );
    assert( ascii == base91::decode( text91 ) );

    assert(  ascii.size() < text91.size() );
    assert(  ascii.size() < text64.size() );
    assert( text91.size() < text64.size() );

    auto overhead = [&]( int size ) -> int { return ((size*100/ascii.size())-100); };

    std::cout << ascii << std::endl;
    std::cout << " - ";
    std::cout << "original: " <<  ascii.size() << " bytes (+" << overhead( ascii.size()) << "% overhead) vs ";
    std::cout << "base64: "   << text64.size() << " bytes (+" << overhead(text64.size()) << "% overhead) vs ";
    std::cout << "base91: "   << text91.size() << " bytes (+" << overhead(text91.size()) << "% overhead) ";
    std::cout << std::endl << std::endl;
}

int main()
{
    // [ref] http://en.wikipedia.org/wiki/Base64
    compare( "Man is distinguished, not only by his reason, but by this singular passion from\n"
     "other animals, which is a lust of the mind, that by a perseverance of delight in the continued\n"
     "and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure." );

    compare( "hello world \x1\x2");

    std::cout << "All ok." << std::endl;
    return 0;
}
