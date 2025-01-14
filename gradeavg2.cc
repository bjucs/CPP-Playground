#include <iomanip> 
#include <ios> 
#include <iostream> 
#include <string> 
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::setprecision;
using std::streamsize;
using std::vector;

// Chapter 3.2
/* 
Vector concepts: 
- vector<T>::size_type retrieved when getting vector.size()
- vector.push_back(x) is an append function
- vector does not have to explicitly allocate memory 
- for functions like sort(...), vector.begin() and vector.end() must be 
specified as bounds 
*/
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
    vector<double> all_hw;

    double hw;
    while (cin >> hw) { 
        count++;
        all_hw.push_back(hw);
    }

    // Specific `vec_sz` is defined from the vector's size_type type
    typedef vector<double>::size_type vec_sz;
    vec_sz size = all_hw.size();

    // Sort & calculate median value of vector -> take average 
    // of low+high medians for even length
    sort(all_hw.begin(), all_hw.end());

    vec_sz mid = size/2;
    double median = size % 2 == 0 ? (all_hw[mid-1] + all_hw[mid]) / 2: all_hw[mid];

    streamsize prec = cout.precision();

    double midterm_weighted = 0.2 * midterm;
    double final_weighted = 0.4 * final;
    double hw_weighted = 0.4 * median;
    double total_score = midterm_weighted + final_weighted + hw_weighted;

    cout << "Your final grade is: " << setprecision(3) << total_score << setprecision(prec) << endl;
    return 0;
}