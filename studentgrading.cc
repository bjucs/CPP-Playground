#include <string> 
#include <vector> 
#include <iostream>
#include <limits>
#include <ios>
#include <sstream> 
#include <iomanip> 

using std::string;
using std::vector;
using std::domain_error;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::istringstream;
using std::ws;

struct Student_info { 
    string name;
    double midterm, final;
    vector<double> homework;
};

double get_median(vector<double> values) { 
    if (values.size() == 0) { 
        throw domain_error("Empty vector of values");
    }

    sort(values.begin(), values.end());

    typedef vector<string>::size_type vec_sz;
    vec_sz mid = values.size() / 2;

    return values.size() % 2 == 1 ? values[mid]:(values[mid] + values[mid-1])/2;
}

double calculate_final_grade(double midterm_score, double final_score, double hw_score) { 
    return (0.2 * midterm_score) + (0.4 * final_score) + (0.4 * hw_score);
}

void display_final_output(vector<Student_info> students) { 
    streamsize prec = cout.precision();
    cout << setprecision(3);

    for (auto it = students.begin(); it != students.end(); it++) { 
        cout << endl;
        cout << "Student name: " << it->name << endl;
        cout << "Student final grade: " << calculate_final_grade(it->midterm, it->final, get_median(it->homework)) << endl;
    }

    setprecision(prec);
}

int main() { 
    bool continue_input = true;
    vector<Student_info> students;

    while (continue_input) { 
        cout << "Please enter student name, followed by midterm, final, and hw grades (or `q` to exit): ";

        string name;
        double midterm, final;
        vector<double> all_hw;

        string line;
        getline(cin, line);

        istringstream input_stream(line);

        // Skip any leading whitespace
        input_stream >> ws;
        getline(input_stream, name, ' ');

        // Terminate if `q` is inputted followed by anything else
        if (name == "q") { 
            continue_input = false;
        } else { 
            if (input_stream >> midterm >> final) { 
                double hw; 
                while (input_stream >> hw) { 
                    all_hw.push_back(hw);
                }

                if (all_hw.size() != 0) { 
                    Student_info student = {name, midterm, final, all_hw};
                    students.push_back(student);
                } else { 
                    cout << "Incorrect number of arguments (must have name, midterm & final exam grades, and at least one HW)" << endl;
                }
            } else { 
                cout << "Incorrect number of arguments (must have name, midterm & final exam grades, and at least one HW)" << endl;
            }
        }
    }

    if (students.size() != 0) { 
        display_final_output(students);
    }

    return 0;
}