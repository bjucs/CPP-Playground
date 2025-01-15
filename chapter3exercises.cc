#include <string> 
#include <vector>
#include <iostream> 
#include <iterator> 

using namespace std;

// Exercises 3.3 -> Get number of distinct strings in vector
int get_num_distinct_strings(vector<string> strings) { 
    // Sorting is necessary because `unique(...)` only checks if adjacent 
    // elements are duplicates
    sort(strings.begin(), strings.end());
    vector<string>::iterator it = unique(strings.begin(), strings.end());
    strings.resize(distance(strings.begin(), it));

    return strings.size();
}

string get_shortest_string(vector<string> strings) { 
    if (strings.empty()) { 
        return "";
    }

    /* `auto` here is a pointer, and the iterator is essentially a pointer
    of the vector's type */ 
    auto shortest = strings.begin();

    for (auto it = strings.begin(); it != strings.end(); it++) { 
        if (it->length() < shortest->length()) { 
            shortest = it;
        }
    }

    return *shortest;
}

string get_longest_string(vector<string> strings) { 
    if (strings.empty()) { 
        return "";
    }

    auto longest = strings.begin();

    for (auto it = strings.begin(); it != strings.end(); it++) { 
        if (it->length() > longest->length()) { 
            longest = it;
        }
    }

    return *longest;
}

int main() { 
    vector<string> strings = {"Brian", "Sydney", "Brian", "Ben", "chr1s"};

    cout << "Number of distinct strings: " << get_num_distinct_strings(strings) << endl;
    cout << "Shortest string: " << get_shortest_string(strings) << endl; 
    cout << "Longest string: " << get_longest_string(strings) << endl; 
    
    return 0;
}
