#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include "Student_info.h"
#include "grade.h"

using std::list;
using std::vector;
using std::istream;
using std::back_inserter;
using std::remove_copy_if;
using std::remove_if;
using std::find;
using std::stable_partition;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents 
        hw.clear();

        // read homework grades 
        double x;
        while (in >> x) {
            hw.push_back(x);
        }
 
        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}

istream& read(istream& is, Student_info& s) {
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;

    // read and store all the student's homework grades
    read_hw(is, s.homework);

    return is;
}

bool did_all_hw(const Student_info& s) {
    return (find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}

bool midterm_higher_than_final(const Student_info& s) {
    return s.midterm > s.final;
}

// single-pass solution
Student_group extract_students(Student_group& students, bool criteria(const Student_info& s)) {
    Student_group::iterator iter = stable_partition(students.begin(), students.end(), criteria);
    Student_group fails(iter, students.end());
    students.erase(iter, students.end());
    return fails;
}

/*
// two-pass solution
Student_group extract_fails(Student_group& students) {
    Student_group fails;

    remove_copy_if(students.begin(), students.end(), back_inserter(fails), pgrade);
    students.erase(remove_if(students.begin(), students.end(), fgrade), students.end());

    return fails;
}
*/
