#include <iomanip> 
#include <ios> 
#include <iostream> 
#include <string> 

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;

// Chapter 3.1 
int main() { 
    cout << "Please enter your first name: ";

    string name; 
    cin >> name; 

    const string greeting = "Hello, " + name + "!\n";
    cout << greeting << endl;

    cout << "Please enter your midterm and final exam grades: ";
    double midterm, final;

    // Terminates with error code (!0) if the two doubles were not read successfully 
    if (!(cin >> midterm >> final)) { 
        return -1;
    }

    cout << "Please enter your homework grades followed by EOF (Ctrl + D): ";
    int count = 0;
    double sum = 0;

    double hw;
    // Keep reading in double values until EOF (use input as loop conditional)
    while (cin >> hw) { 
        count++;
        sum += hw; 
    }

    // Gather & restore standard precision after done outputting
    streamsize prec = cout.precision();

    double midterm_weighted = 0.2 * midterm;
    double final_weighted = 0.4 * final;
    double hw_weighted = 0.4 * (sum / count);
    double total_score = midterm_weighted + final_weighted + hw_weighted;

    cout << "Your final grade is: " << setprecision(3) << total_score << setprecision(prec) << endl;

    return 0;
}
