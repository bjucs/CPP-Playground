#include <string> 
#include <vector> 

using std::string;
using std::vector;
using std::domain_error;

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