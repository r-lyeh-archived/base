Base91 <a href="https://travis-ci.org/r-lyeh/base91"><img src="https://api.travis-ci.org/r-lyeh/base91.svg?branch=master" align="right" /></a>
======

- Base91 is a lightweight binary-to-text data de/encoder (C++03).
- Base91 is 19% to 10% smaller than Base64; additional Base64 de/encoder is also provided.
- Base91 is JSON, XML and TSV friendly. Encoded data can be "quoted", splitted with tabs, spaces, linefeeds and carriages.
- Base91 is tiny and header-only. Around ~250 LOC.
- Base91 is self-contained. No external dependencies.
- Base91 is zlib/libpng licensed.

## Sample
```c++
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
```

## Possible output
```
Hello world from BASE64! ☺☻ <-> SGVsbG8gd29ybGQgZnJvbSBCQVNFNjQhIAEC
Hello world from BASE91! ☺☻ <-> \OwJh\Io2Tv!lE^jpr4JuucSS5V*pBkAB
```

## Licenses
- Base91, zlib/libpng licensed.
- Original basE91 by Joachim Henke, [BSD licensed](http://base91.sourceforge.net/).
- Original base64 implementation by René Nyffenegger, [zlib/libpng licensed](http://www.adp-gmbh.ch/cpp/common/base64.html).

## Changelog
- v1.0.1 (2015/12/07): Update sample
- v1.0.0 (2014/04/26): Base64 support
- v0.0.0 (2013/04/12): Initial commit
