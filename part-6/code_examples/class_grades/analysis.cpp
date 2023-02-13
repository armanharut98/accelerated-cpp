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
double median_analysis(const vector<Student_info>& students)
{
    vector<double> grades; 
    transform(students.begin(), students.end(), back_inserter(grades), grade_aux);
    return median(grades);
}

double average_analysis(const vector<Student_info>& students)
{
    vector<double> grades;
    transform(students.begin(), students.end(), back_inserter(grades), average_grade);
    return median(grades);
}

// median of the nonzero elements of s.homework, or 0 if no such elements exist 
double optimistic_median_analysis(const Student_info& s)
{
    vector<double> nonzero;
    remove_copy(s.homework.begin(), s.homework.end(), back_inserter(nonzero), 0);

    if (nonzero.empty())
        return grade(s.midterm, s.final, 0);
    else
        return grade(s.midterm, s.final, median(nonzero));
}

void write_analysis(ostream& out, const string& name,
            double analysis(const vector<Student_info>&),
            const vector<Student_info>& did,
            const vector<Student_info>& didnt)
{
    out << name << ": median(did) = " << analysis(did) <<
                ", median(didnt) = " << analysis(didnt) << endl;
}
