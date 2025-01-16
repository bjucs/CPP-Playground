#ifndef MEDIAN
#define MEDIAN

#include <algorithm>
#include <stdexcept>
#include <vector>

using std::vector;
using std::domain_error;

double get_median(vector<double> values) { 
    if (values.size() == 0) { 
        throw domain_error("Empty vector of values");
    }

    sort(values.begin(), values.end());

    typedef vector<double>::size_type vec_sz;
    vec_sz mid = values.size() / 2;

    return values.size() % 2 == 1 ? values[mid]:(values[mid] + values[mid-1])/2;
}

#endif