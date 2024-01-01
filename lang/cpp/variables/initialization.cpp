#include <iostream>

int main()
{
    // Copy initialization
    // When an initializer is provided after an equals sign, this is called
    // copy initialization. This form of initialization was inherited from C.
    {
        int width = 5; // copy initialization of value 5 into variable width
        std::cout << "width = " << width << "\n";
    }

    // Direct initialization
    // Initially introduced to allow for more efficient initialization
    // of complex objects (those with class types)
    {
        int width( 6 ); // direct initialization of value 5 into variable width
        std::cout << "width = " << width << "\n";
    }

    // List initialization
    // The modern way to initialize objects in C++ is to use a form of
    // initialization that makes use of curly braces.
    {
        int width { 5 };    // direct list initialization of value 5 into variable width
        int height = { 6 }; // copy list initialization of value 6 into variable height
        int depth {};       // value initialization (see next section)

        std::cout << "width = " << width << "\n";
        std::cout << "height = " << height << "\n";
        std::cout << "depth = " << depth << "\n";
    }

}

