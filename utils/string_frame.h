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

string pad_string(const string& str, int length) { 
    int diff = length - str.size();
    int left_pad = diff / 2, right_pad = diff - left_pad;

    string left_space(left_pad, ' '), right_space(right_pad, ' ');

    return left_space + str + right_space;
}

// Use a reference to avoid extra memory for pass-by-value vector copy
vector<string> frame(const vector<string>& strings) { 
    typedef string::size_type str_sz;

    if (strings.empty()) { 
        throw domain_error("Empty vector of strings");
    }

    // max_element(...) returns an iterator, which is why the `->` is needed
    vector<string> framed_strings;
    str_sz max_len = max_element(strings.begin(), strings.end(), compare_length)->size();

    string horizontal_border(max_len + 4, '*');
    string line;
    str_sz line_len = 0; 

    framed_strings.push_back(horizontal_border);

    auto it = strings.begin();
    while (it != strings.end()) { 
        str_sz curr_len = (*it).size();

        if (line_len == 0) { 
            line.append(*it);
            line_len += curr_len;
        }
        else { 
            if (line_len + curr_len + 1 <= max_len) { 
                line.append(" " + *it);
                line_len += (curr_len + 1);
            } else { 
                line = pad_string(line, max_len);
                framed_strings.push_back("* " + line + " *");
                line.clear();
                line_len = 0;

                line.append(*it);
                line_len += curr_len;
            }
        }
        it++;
    }
    
    // Process final line if not appended yet 
    if (!line.empty()) { 
        line = pad_string(line, max_len);
        framed_strings.push_back("* " + line + " *");
    }

    framed_strings.push_back(horizontal_border);

    return framed_strings;
}

#endif