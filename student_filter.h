#ifndef STUDENT_F
#define STUDENT_F

#include <stdexcept>
#include <list>
#include "student_info.h"
#include "utils/median.h"

using std::list;

double grade(const Student_info& s) { 
    return (0.2 * s.midterm) + (0.4 * s.final) + (0.4 * get_median(s.homework));
}

bool failing_grade(const Student_info& s) { 
    return grade(s) < 60;
}

/* Using `list` instead of `vector` allows us to use std::erase in O(1) while
looping through with an iterator, bringing total TC to O(n) instead of O(n^2)
with a vector. This is due to vector needing to shift memory addresses of 
other elements (array-backed) and list only changing points (linked struct) */ 
list<Student_info> extract_fails(list<Student_info>& students) { 
    list<Student_info> failed;

    auto it = students.begin();
    while (it != students.end()) { 
        if (failing_grade(*it)) { 
            failed.push_back(*it);
            it = students.erase(it);
        } else { 
            it++;
        }
    }

    /* Since we input `list<Student_info>&` reference type, we 
    concurrently modify the original list to only include passing grades, and 
    return the failing grades (which we can decide what to do with) */
    return failed; 
}

#endif