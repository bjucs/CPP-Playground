#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include <string>

using std::string;
using std::vector;
using std::fabs;

struct Student_info { 
    string name;
    double midterm, final;
    vector<double> homework;

    // Define the equality operator
    bool operator==(const Student_info& other) const {
        if (name != other.name) return false;

        // Compare midterm and final scores with some tolerance for floating-point comparisons
        const double epsilon = 1e-9; 
        if (fabs(midterm - other.midterm) > epsilon) return false;
        if (fabs(final - other.final) > epsilon) return false;

        if (homework.size() != other.homework.size()) return false;
        for (size_t i = 0; i < homework.size(); ++i) {
            if (fabs(homework[i] - other.homework[i]) > epsilon) return false;
        }

        return true; 
    }
};

#endif