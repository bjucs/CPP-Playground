#ifndef SPLIT
#define SPLIT

#include <string> 
#include <vector>
#include <algorithm> 
#include <cctype> 

using std::string;
using std::vector;
using std::find_if;

bool not_space(char c) { 
    return !isspace(c);
}

vector<string> split(const string& str) { 
    vector<string> all_strs;

    auto it = str.begin();
    while (it != str.end()) { 
        /*  Set `it` to first non-space character, effectively ignoring leading whitespace, and `it2` to the first space character -> this works because
        the right index/iterator is exclusive */ 
        it = find_if(it, str.end(), not_space);
        auto it2 = find_if(it, str.end(), isspace);

        if (it != str.end()) { 
            all_strs.push_back(string(it, it2));
        }
        it = it2; 
    }

    return all_strs; 
}


#endif