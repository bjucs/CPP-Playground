#ifndef STUDENT_F
#define STUDENT_F

#include <list>
#include <cctype> 
#include "student_info.h"
#include "utils/median.h"

using std::list;
using std::find;

double grade(const Student_info& s) { 
    return (0.2 * s.midterm) + (0.4 * s.final) + (0.4 * get_median(s.homework));
}

bool failing_grade(const Student_info& s) { 
    return grade(s) < 60;
}

/* find(<begin>, <end>, <val>) returns the <end> iterator if <val> isn't found.
This works because <end> is actually the memory address after the last value 
in the collection (garbage val), so it can't return a valid value's address */ 
bool missing_hw(const Student_info& s) { 
    return ((find(s.homework.begin(), s.homework.end(), 0)) != s.homework.end());
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

list<Student_info> extract_missing_hw(list<Student_info>& students) { 
    list<Student_info> missing_hw_students;

    auto it = students.begin();
    while (it != students.end()) { 
        if (missing_hw(*it)) { 
            missing_hw_students.push_back(*it);
            it = students.erase(it);
        } else { 
            it++;
        }
    }

    return missing_hw_students; 
}

#endif