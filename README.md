base91x
=======

- base91x is a lightweight binary-to-text data encoder and decoder written in C++.
- base91x features 19% to 10% less overhead than base64.
- base91x is JSON friendly. Encoded data can be "quoted" with no escaping.
- base91x is XML friendly. Encoded data can be "quoted" as attribute or written as text() with no escaping.
- base91x is TSV friendly. Encoded data can be splitted with tabs, spaces, linefeeds and carriages.
- Tiny. Around ~250 LOC. One file and one header.
- No external dependencies.
- MIT licensed.

about
-----
- base91x is a basE91 spec modification. Original basE91 by Joachim Henke can be found here: http://base91.sourceforge.net/
- additionally, a base64 implementation is provided for comparison. Based on code by René Nyffenegger.

sample
------
```c++
#include <iostream>
#include "base91x.hpp"

int main() {
    std::string encoded = base91x::encode("hello world from base91x! \x1\x2");
    std::string decoded = base91x::decode(encoded);

    std::cout << encoded << " <-> " << decoded << std::endl;
}
```

possible output
---------------
```
TPwJh\Io2Tv!lE^jpr4JB*BT=!V*wQbL6FA <-> hello world from base91x! ☺☻
```
