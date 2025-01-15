#include <iomanip> 
#include <ios> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector>

using namespace std;

// Chapter 4.1 
double get_median(vector<double> values) { 
    sort(values.begin(), values.end());

    typedef vector<double>::size_type vec_sz;
    vec_sz size = values.size();
    vec_sz mid = size / 2;

    return size % 2 == 0 ? (values[mid-1] + values[mid])/2:values[mid];
}

double calculate_final_grade(vector<double> hw_scores, double midterm_score, double final_score) { 
    double median = get_median(hw_scores);
    return (0.2 * midterm_score) + (0.4 * final_score) + (0.4 * median);
}

void display_final_output(vector<string> student_names, vector<double> student_final_grades) { 
    typedef vector<string>::size_type vec_sz;
    vec_sz size = student_names.size();
    for (vec_sz i = 0; i < size; i++) { 
        cout << "Student name: " << student_names[i] << endl;
        cout << "Student final grade: " << student_final_grades[i] << endl;
        cout << endl;
    }
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

        vector<double> all_hw; 

        cout << "Please enter your homework grades: ";
        
        // Used to ignore leftover input from the buffer 
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        string line;
        getline(cin, line);
        /* Used in conjunction with `stream >> hw` to extract all double values
        from the line of input used for HW scores */ 
        istringstream stream(line);
        
        double hw; 
        while (stream >> hw) { 
            all_hw.push_back(hw);
        }

        double total_score = calculate_final_grade(all_hw, midterm, final);

        student_names.push_back(name);
        student_final_grades.push_back(total_score);

        cout << endl;
        cout << "Please enter your first name (or EOF to move on): ";
    } 

    cout << endl;

    streamsize prec = cout.precision();
    cout << setprecision(3);

    display_final_output(student_names, student_final_grades);

    setprecision(prec);
    return 0;
} 