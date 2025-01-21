#ifndef STRING_F
#define STRING_F

#include <string>
#include <vector>
#include <algorithm> 
#include <stdexcept> 

using std::string;
using std::vector;
using std::domain_error;
using std::max_element;

bool compare_length(const string& a, const string& b) { 
    return a.size() < b.size();
}

vector<string> frame(const vector<string>& strings) { 
    typedef string::size_type str_sz;

    if (strings.empty()) { 
        throw domain_error("Empty vector of strings");
    }

    // max_element(...) returns an iterator, which is why the `->` is needed
    vector<string> framed_strings;
    str_sz max_len = max_element(strings.begin(), strings.end(), compare_length)->size();

    string horizontal_border('*', max_len + 2);
    framed_strings.push_back(horizontal_border);
    framed_strings.push_back(horizontal_border);

    /* TODO: implement logic for formatting all strings (words) within the 
    input vector */ 
    return framed_strings;
}

#endif