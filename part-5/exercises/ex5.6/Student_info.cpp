#include <list>
#include <vector>
#include "Student_info.h"
#include "grade.h"

using std::list;    using std::istream;
using std::vector;

#include <iostream>

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

Student_group extract_fails(Student_group& students) {
    Student_group failed;
    Student_group::size_type passCount = 0;

    Student_group::size_type i = 0;
    while (i != students.size()) {
        if (fgrade(students[i])) {
            failed.push_back(students[i]);
        } else {
            students.insert(students.begin(), students[i++]);
            ++passCount;
        }
        ++i;
    }

    students.resize(passCount);

    return failed;
}
