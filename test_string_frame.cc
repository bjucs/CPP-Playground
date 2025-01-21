#include <iostream> 
#include "utils/string_frame.h"

using std::cout;
using std::endl;

void print_framed_strings(vector<string> framed_strings) { 
    auto it = framed_strings.begin();
    while (it != framed_strings.end()) { 
        cout << *it << endl;
        it++;
    }
}

int main() { 
    vector<string> test_vec = {"Brian", "LlamaV2", "Rohan", "Long_Snake_Case_String", "camelCase"};

    try { 
        vector<string> result_vec = frame(test_vec);
        print_framed_strings(result_vec);
        return 0;
    } catch (domain_error) { 
        cout << "Can't frame an empty vector" << endl;
        return -1;
    }
}