#include <iostream> 
#include "utils/string_frame.h"

using std::cout;
using std::endl;

int main() { 
    vector<string> test_vec = {"Brian", "LlamaV2", "Rohan", "Long_Snake_Case_String"};

    try { 
        vector<string> result_vec = frame(test_vec);

        auto it = result_vec.begin();
        while (it != result_vec.end()) { 
            cout << *it << endl;
            it++;
        }

        return 0;
    } catch (domain_error) { 
        cout << "Can't frame an empty vector" << endl;
        return -1;
    }
}