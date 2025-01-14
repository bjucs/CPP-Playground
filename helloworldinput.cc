#include <iostream> 
#include <string> 

// Chapter 1.1, 1.2
int main() { 
    std::cout << "Please enter your first name: ";

    // Declare name string & read stdin -> name
    std::string name; 
    std::cin >> name; 

    // Buffer -> used to optimize I/O operations
    // Buffer is flushed by 1. being full, 
    // 2. reading from stdin, or 3. explicit prompt

    const std::string greeting = "Hello, " + name + "!"; 
    // Can use notation of <var name>(<len>, <char>) to initialize string 
    // of duplicate char types
    const std::string spaces(greeting.size(), ' '); 

    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');

    std::cout << first << std::endl;
    std::cout << second << std::endl;
    std::cout << "* " + greeting + " *" << std::endl;
    std::cout << second << std::endl; 
    std::cout << first << std::endl;

    return 0;
}