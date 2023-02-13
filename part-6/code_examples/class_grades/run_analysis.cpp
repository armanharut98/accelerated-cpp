#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"
#include "analysis.h"

using std::cin;             using std::setprecision;
using std::cout;            using std::sort;
using std::domain_error;    using std::streamsize;
using std::endl;            using std::string;
using std::max;             using std::vector;

int main() {
    vector<Student_info> did, didnt;
    Student_info student;

    // read all the records, separating them based on whether all homework was done 
    while (read(cin, student)) {
        if (did_all_hw(student))
            did.push_back(student);
        else
            didnt.push_back(student);
    }

    // check that both groups contain data 
    if (did.empty()) {
        cout << "No student did all the homework!" << endl;
        return 1;
    }
    if (didnt.empty()) {
        cout << "Every student did all the homework!" << endl;
        return 1;
    }

    // do the analyses
    write_analysis(cout, "median", median_analysis, did, didnt);
    write_analysis(cout, "average", average_analysis, did, didnt);
    //write_analysis(cout, "median of homework turned in", optimistic_median_analysis, did, didnt);

    return 0;
}

/*
int main() {
    vector<Student_info> students;
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
    // alphabetize the student records
    sort(students.begin(), students.end(), compare);
    // write the names and grades
    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name
            << string(maxlen + 1 - students[i].name.size(), ' ');
        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
                << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}
*/