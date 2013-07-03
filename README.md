base91x
=======

- base91x is a lightweight binary/text data encoder and decoder written in C++. 
- base91x features 19% to 10% less overhead than base64.
- base91x is JSON friendly. Encoded data can be "quoted" with no escaping.
- base91x is XML friendly. Encoded data can be "quoted" as attribute or written as text() with no escaping.
- Tiny. Less than 100 lines of code excluding comments.
- No dependencies.
- MIT licensed.

about
-----
base91x is a basE91 modification. Original basE91 by Joachim Henke can be found here: http://base91.sourceforge.net/

sample
------
```c++
#include <iostream>
#include "base91x.hpp"

int main( int argc, const char **argv )
{
    std::string encoded = base91x::encode("hello world \x1\n");
    std::string decoded = base91x::decode(encoded);

    std::cout << decoded;
    return 0;
}
```
