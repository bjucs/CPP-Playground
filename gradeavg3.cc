#include <iomanip> 
#include <ios> 
#include <iostream> 
#include <string> 
#include <vector>

using namespace std;

double calculate_final_grade(vector<double> hw_scores, double midterm_score, double final_score) { 
    sort(hw_scores.begin(), hw_scores.end());

    // Since hw_scores is of fixed size 3 
    double median = hw_scores[1];
    return (0.2 * midterm_score) + (0.4 * final_score) + (0.4 * median);
}

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
        double total_score = calculate_final_grade(all_hw, midterm, final);

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