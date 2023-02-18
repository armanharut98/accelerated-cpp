#include <stdexcept>
#include <vector>
#include <algorithm>
#include "grade.h"
#include "median.h"
#include "average.h"
#include "Student_info.h"

using std::domain_error;
using std::vector;
using std::remove_copy;

double grade(double midterm, double final, double homework) {
    return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

bool fgrade(const Student_info& s) {
    return grade(s) < 6;
}

bool pgrade(const Student_info& s) {
    return !fgrade(s);
}

double grade_aux(const Student_info& s) {
    try {
        return grade(s);
    } catch (domain_error) {
        return grade(s.midterm, s.final, 0);
    }
}

double average_grade(const Student_info& s) {
    return grade(s.midterm, s.final, average(s.homework));
}

double optimistic_median_grade(const Student_info& s) {
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty()) {
        return grade(s.midterm, s.final, 0);
    } else {
        return grade(s.midterm, s.final, median(nonzero));
    }
}
