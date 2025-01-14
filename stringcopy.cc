#include <iostream>
#include <string>

// Chapter 1.3 
int main() {
    std::string s = "Hello, World!";
    std::string s2 = s; // Deep copy is made

    s2[0] = 'h'; // Modify s2

    std::cout << "s: " << s << std::endl;   // Output: "Hello, World!"
    std::cout << "s2: " << s2 << std::endl; // Output: "hello, World!"
    return 0;
}
