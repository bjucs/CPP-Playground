#include <iostream> 
#include <string> 

// Chapter 2.5.1, 2.5.2

/* By signifying `using <library>:<feature>`, you indicate that whenever
you type <feature> by itself, you are referring to the version from 
<library> */ 
using std::cout;
using std::cin;
using std::endl;
using std::string;

int main() { 
    cout << "Please enter your first name: ";

    string name; 
    cin >> name; 

    const string greeting = "Hello, " + name + "!";
    const string formatted_greeting = "* " + greeting + " *";

    const string spaces(greeting.size(), ' ');
    const string pad_row = "* " + spaces + " *";
    const string star_border(pad_row.size(), '*');

    const int vertical_pad = 2;
    const int total_rows = vertical_pad * 2 + 3;

    // Example of for loop syntax / declaration
    for (int r = 0; r < total_rows; r++) { 
        if (r == 0 || r == total_rows - 1) { 
            cout << star_border << endl;
        }
        else if (r == total_rows / 2) { 
            cout << formatted_greeting << endl;
        }
        else { 
            cout << pad_row << endl;
        }
    }
}