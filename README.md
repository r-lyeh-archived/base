Base <a href="https://travis-ci.org/r-lyeh/base"><img src="https://api.travis-ci.org/r-lyeh/base.svg?branch=master" align="right" /></a><a href="LICENSE"><img src="https://img.shields.io/badge/license-zlib/libpng-blue.svg" align="right" /></a>
====

- [x] Lightweight binary-to-text data de/encoders (C++03).
- [x] Base64: canonical implementation.
- [x] Base85: 17% to 08% smaller than Base64, still quotable.
- [x] Base91: 19% to 10% smaller than Base64, still quotable, JSON, XML and TSV friendly.
- [x] Base91: Encoded data can be "quoted", splitted with tabs, spaces, linefeeds and carriages.
- [x] Tiny, self-contained, header-only.
- [x] ZLIB/LibPNG licensed.

## Sample
```c++
#include <iostream>
#include <string>
#include "base.hpp"

int main() {
    std::string encoded_64 = base64::encode("Hello world from BASE64! \x1");
    std::string decoded_64 = base64::decode(encoded_64);
    std::cout<< decoded_64 << " <-> " << encoded_64 << std::endl;

    std::string encoded_85 = base85::encode("Hello world from BASE85! \x1");
    std::string decoded_85 = base85::decode(encoded_85);
    std::cout<< decoded_85 << " <-> " << encoded_85 << std::endl;

    std::string encoded_91 = base91::encode("Hello world from BASE91! \x1");
    std::string decoded_91 = base91::decode(encoded_91);
    std::cout<< decoded_91 << " <-> " << encoded_91 << std::endl;
}
```

## Possible output
```
Hello world from BASE64! ☺ <-> SGVsbG8gd29ybGQgZnJvbSBCQVNFNjQhIAE=
Hello world from BASE85! ☺ <-> nm=QNzY<mxA+]new].*bavnv)ml0dFaoqGy
Hello world from BASE91! ☺ <-> \OwJh\Io2Tv!lE^jpr4JuucSS5V*pBkA
```

## Licenses
- Base, zlib/libpng licensed.
- Original basE91 by Joachim Henke, [BSD licensed](http://base91.sourceforge.net/).
- Original base64 implementation by René Nyffenegger, [zlib/libpng licensed](http://www.adp-gmbh.ch/cpp/common/base64.html).

## Changelog
- V1.0.2 (2016/04/20): Base85 support (custom Z85); In-place API; Project renamed
- v1.0.1 (2015/12/07): Update sample
- v1.0.0 (2014/04/26): Base64 support
- v0.0.0 (2013/04/12): Initial commit (custom basE91)
