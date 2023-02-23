#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <ostream>
#include "Student_info.h"
#include "grade.h"
#include "median.h"

using std::vector;
using std::string;
using std::transform;
using std::remove_copy;
using std::back_inserter;
using std::ostream;
using std::endl;

double perform_analysis(const Student_group& students, double grading_policy(const Student_info&)) {
    vector<double> grades;

    transform(students.begin(), students.end(), back_inserter(grades), grading_policy);
    return median(grades);
}

void write_analysis(ostream& out, const string& name,
                    double grading_policy(const Student_info&),
                    Student_group did,
                    Student_group didnt)
{
    out << name << ": median(did) = " << perform_analysis(did, grading_policy) 
                << ", median(didnt) = " << perform_analysis(didnt, grading_policy) << endl;
}

