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

int main() { 
    vector<string> strings = {"Brian", "Sydney", "Brian", "Ben", "chr1s"};
    cout << "Number of distinct strings: " << get_num_distinct_strings(strings) << endl;
    
    return 0;
}
