#include <string> 

// Chapter 1.3 

int main() { 
    // Compiles
    const std::string hello = "Hello";
    const std::string msg = hello + " World!";

    // const std::string exc = "!";
    // const std::string msg2 = "Hello" + " World" + exc;
    // Does not compile -> can only concatenate string + string literal 
    // or string + string, but NOT string literal + string literal. 
    // (You can alternate types though, as long as SL is not next to SL)
}