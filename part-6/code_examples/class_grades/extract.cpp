#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <list>
#include "grade.h"
#include "Student_info.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::list;

int main() {
    Student_group students;
    Student_info record;
    string::size_type maxlen = 0; // the length of the longest name

    // read and store all the students data.
    // Invariant: students contains all the student records read so far
    // maxlen contains the length of the longest name in students
    while (read(cin, record)) {
        // find length of longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }
    // extract failed students
    Student_group fails = extract_fails(students);

    // alphabetize the student records
    // students.sort(compare);
    sort(students.begin(), students.end(), compare);

    // write the names and grades of students who passed
    for (Student_group::const_iterator iter = students.begin(); iter != students.end(); ++iter) {
        // write the name, padded on the right to maxlen + 1 characters
        cout << iter->name
            << string(maxlen + 1 - iter->name.size(), ' ');
        // compute and write the grade
        double final_grade = grade(*iter);
        streamsize prec = cout.precision();
        cout << setprecision(3) << final_grade
            << setprecision(prec) << endl;
    }

    cout << "The following students have failed: ";
    Student_group::const_iterator iter = fails.begin();
    while (iter != fails.end()) {
        cout << iter->name << " ";
        ++iter;
    }
    cout << endl;

    return 0;
}