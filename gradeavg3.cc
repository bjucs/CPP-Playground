#include <iomanip> 
#include <ios> 
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

// Exercise 3-5 
int main() { 
    cout << "Please enter your first name: ";

    vector<string> student_names;
    vector<double> student_final_grades;
    string name;

    while (cin >> name) { 
        const string greeting = "Hello, " + name + "!\n";
        cout << greeting << endl;

        cout << "Please enter your midterm and final exam grades: ";
        double midterm, final;

        if (!(cin >> midterm >> final)) { 
            return -1;
        }

        // Fixed number of homeworks (3)
        cout << "Please enter your 3 homework grades: ";
        double hw1, hw2, hw3;
        if (!(cin >> hw1 >> hw2 >> hw3)) { 
            return -1;
        }

        vector<double> all_hw = {hw1, hw2, hw3};
        sort(all_hw.begin(), all_hw.end());

        double median = all_hw[1];
        double total_score = (0.2 * midterm) + (0.4 * final) + (0.4 * median);

        student_names.push_back(name);
        student_final_grades.push_back(total_score);

        cout << endl;
        cout << "Please enter your first name (or EOF to move on): ";
    } 

    cout << endl;

    streamsize prec = cout.precision();
    cout << setprecision(3);

    typedef vector<string>::size_type vec_sz;
    vec_sz size = student_names.size();
    for (vec_sz i = 0; i < size; i++) { 
        cout << "Student name: " << student_names[i] << endl;
        cout << "Student final grade: " << student_final_grades[i] << endl;
        cout << endl;
    }

    setprecision(prec);

    return 0;
} 