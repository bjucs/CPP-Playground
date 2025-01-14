#include <iostream> 
#include <string> 

// Chapter 2.2, 2.3
int main() { 
    std::cout << "Please enter your first name: ";

    std::string name; 
    std::cin >> name; 

    const std::string greeting = "Hello, " + name + "!";
    const std::string formatted_greeting = "* " + greeting + " *";

    const std::string spaces(greeting.size(), ' ');
    const std::string pad_row = "* " + spaces + " *";
    const std::string star_border(pad_row.size(), '*');

    // vertical_pad * 2 to account for padding on top & bottom
    // additional 3 rows for top star-row, bottom star-row, msg
    const int vertical_pad = 2;
    const int total_rows = vertical_pad * 2 + 3;

    // Add a newline between input, output
    std::cout << std::endl;

    int r = 0;
    while (r < total_rows) { 
        if (r == 0 || r == total_rows - 1) { 
            std::cout << star_border << std::endl;
        }
        else if (r == total_rows / 2) { 
            std::cout << formatted_greeting << std::endl;
        }
        else { 
            std::cout << pad_row << std::endl;
        }
        r++;
    }

    return 0;
}