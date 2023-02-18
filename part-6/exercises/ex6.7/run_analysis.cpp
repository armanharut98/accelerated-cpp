#include <vector>
#include <string>
#include <iostream>
#include "Student_info.h"
#include "analysis.h"
#include "grade.h"

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {
    vector<Student_info> did;
    Student_info student;
    // read all the records, separating them based on whether all homework was done
    while (read(cin, student)) {
        did.push_back(student);
    }

    vector<Student_info> didnt = extract_students(did, did_all_hw);

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
    write_analysis(cout, "median of homework turned in", 
        optimistic_median_analysis, did, didnt);

    return 0;

    return 0;
}