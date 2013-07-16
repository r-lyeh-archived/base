#pragma once
#include <string>

namespace base91x
{
    std::string encode( const std::string &binary );
    std::string decode( const std::string &text );
}

namespace base91 = base91x;
