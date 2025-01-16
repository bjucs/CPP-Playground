#include "studentgrading.cc"

// Chapter 4.2.2
bool compare(const Student_info& s1, const Student_info& s2) { 
    double s1_final = calculate_final_grade(s1.midterm, s1.final, get_median(s1.homework));
    double s2_final = calculate_final_grade(s2.midterm, s2.final, get_median(s2.homework));

    return s1_final < s2_final;
}

int main() { 
    vector<double> hw_scores_1 = {82.3, 90.5};
    vector<double> hw_scores_2 = {99.9, 100, 100, 100};
    vector<double> hw_scores_3 = {28.3, 58.5};

    double midterm1 = 100, midterm2 = 100, midterm3 = 78.6;
    double final1 = 76, final2 = 98.8, final3 = 45.4;

    Student_info s1 = {"Brian", midterm1, final1, hw_scores_1};
    Student_info s2 = {"Jacob", midterm2, final2, hw_scores_2};
    Student_info s3 = {"Erik", midterm3, final3, hw_scores_3};

    vector<Student_info> students = {s1, s2, s3};
    sort(students.begin(), students.end(), compare);

    display_final_output(students);
}