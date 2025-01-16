#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

using std::string;
using std::vector;

struct Student_info { 
    string name;
    double midterm, final;
    vector<double> homework;
};

#endif