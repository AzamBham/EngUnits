# EngUnits --IN PROGRESS--
EngUnits is a C++ header-only library of engineering unit types(meters, stones, feet, kilograms etc.) and tools, with an emphasis on type safety, efficiency, readability and ease of extension and use. This library is ideal for scientific or engineering problems where consistency and type safety between unit types is required (e.g, a length and a mass cannot be added, a volume and a velocity cannot be compared, dividing pressure by pressure does not yield pressure etc.)

There is built-in support for:

- efficient comparison operator chaining
```c++
#include "engunits/engunits.h"

using namespace engunits::length;

if (feet{10} < meters{10} < miles{10}) //...//;
```

- intuitive mathematical operations
```c++
using namespace engunits;

length::meters m = 5;

area::sqmeters a = m^2; //a equals m to the power of 2

std::cout << a << '\n'; //prints "25m2"
```

- seamless accurate conversion between unit types of the same measurement type
```c++
using namespace engunits::length;

inches i{12};

feet f{i};

std::cout << f << '\n'; //prints "1ft"
```

- rigorous enforcement of physical measurement rules
```c++
using namespace engunits;

mass::stones s{5};

pressure::pascal p{10000};

p+=s //ERROR: you can't add a mass to a pressure
```

Although this library includes support for a number of different unit types, it is trivial to add your own...
```c++
namespace engunits::length{
class MyLength: public LengthUnit<MyLength> {
    public:
        using LengthUnit<MyLength>::LengthUnit;
        
        static constexpr double conversion = 12345; //conversion to si(how many meters make up this unit)
        
        static std::string symbol() {return "MyLen";} //your unit symbol
};  
}
```


Thats less than 7 lines of code! Using your custom unit:
```c++
using namespace engunits::length;

MyLength custom{10};

std::cout << custom << '\n'; //prints "10MyLen"

meters m{12345};

custom = m;

std::cout << custom << '\n' //prints "1MyLen"
```


Also included is a library of constants...
```c++
using namespace engunits;

mass::kilograms MEarth{5.9722e+24};

mass::kilograms MMoon{7.342e+22};

length::meters R{3.844e+8};

force::Newtons grav = constants::G*MEarth*MMoon*(R^-2);
```

...and a library of mathematical equations...
```c++
using namespace engunits;

angle::radians r{constants::pi/2};

length::meters m = meters{10}*maths::sin(r);

std::cout << m << '\n'; //prints "10m"
```
