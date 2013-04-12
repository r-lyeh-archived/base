#pragma once
#include <string>

namespace base91x
{
    std::string encode( const std::string &text );
    std::string decode( const std::string &binary );
}
