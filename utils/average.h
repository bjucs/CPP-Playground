#ifndef AVERAGE
#define AVERAGE

#include <stdexcept>
#include <vector>

using std::vector;
using std::domain_error;

double get_average(vector<double> values) { 
    if (values.size() == 0) { 
        throw domain_error("Empty vector of values");
    }

    double sum = 0;

    for (auto it = values.begin(); it != values.end(); it++) { 
        sum += *it;
    }

    return sum / values.size();
}

#endif