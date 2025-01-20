#include <string> 
#include <vector> 
#include <iostream>
#include <limits>
#include <ios>
#include <sstream> 
#include <iomanip> 
#include "student_info.h"
#include "student_filter.h"

using std::string;
using std::domain_error;
using std::cout;
using std::cin;
using std::endl;
using std::setprecision;
using std::numeric_limits;
using std::streamsize;
using std::istringstream;
using std::ws;

void display_final_output(list<Student_info> students) { 
    streamsize prec = cout.precision();
    cout << setprecision(3);

    for (auto it = students.begin(); it != students.end(); it++) { 
        try { 
            double midterm = it->midterm, final = it->final, hw = get_median(it->homework);
            cout << endl;
            cout << "Student name: " << it->name << endl;
            cout << "Student final grade: " << grade(*it) << endl;
        } catch (domain_error) { 
            cout << "Student did not turn in any homework" << endl; 
        }
    }

    setprecision(prec);
}

/* Compilation flag used to avoid registering `main` of studentgrading.cc
when only the helper functions are needed */ 

#ifndef HELPER_MODE
int main() { 
    bool continue_input = true;
    list<Student_info> students;

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
        extract_fails(students);
        display_final_output(students);
    }

    return 0;
}
#endif