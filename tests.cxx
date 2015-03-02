#include <cassert>
#include <iostream>
#include "base91.hpp"

template<bool show>
void verify( const std::string &ascii ) 
{
    std::string text64 = base<64>::encode(ascii);
    std::string text91 = base<91>::encode(ascii);

    // sanity tests
    assert( ascii == base<64>::decode( text64 ) );
    assert( ascii == base<91>::decode( text91 ) );

    assert(  ascii.size() < text91.size() );
    assert(  ascii.size() < text64.size() );
    assert( text91.size() < text64.size() );

    // split text tests
    std::string split91 = text91.substr(0, 10) + "\r\n\r\n\t\t  " + text91.substr(10);
    assert( ascii == base<91>::decode( split91 ) );

    // display sizes and overhead
    auto overhead = [&]( int size ) -> int { return ((size*100/ascii.size())-100); };

    std::cout << ( show ? std::string() + '\"' + ascii + '\"' : "(hidden text)" ) << std::endl;
    std::cout << "\tdefault: " << overhead( ascii.size()) << "% overhead (total: " <<  ascii.size() << " bytes)\n";
    std::cout << "\tbase-64: "   << overhead(text64.size()) << "% overhead (total: " << text64.size() << " bytes)\n";
    std::cout << "\tbase-91: "   << overhead(text91.size()) << "% overhead (total: " << text91.size() << " bytes)\n";
    std::cout << std::endl;
}

int main() {
    // [ref] http://en.wikipedia.org/wiki/Base64
    verify<true>( "Man is distinguished, not only by his reason, but by this singular passion from\n"
     "other animals, which is a lust of the mind, that by a perseverance of delight in the continued\n"
     "and indefatigable generation of knowledge, exceeds the short vehemence of any carnal pleasure." );

    verify<true>( "hello world \x1\x2");

    std::string charmap;
    for( int i = 0; i < 256; ++i ) charmap += char(i);
    verify<false>( charmap );

    std::cout << "All ok." << std::endl;
}
