#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include "Student_info.h"
#include "analysis.h"

using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    Student_group did, didnt;

    // read all the records, separating them based on whether all homework was done 
    Student_info student;
    while (read(cin, student)) {
        if (did_all_hw(student)) {
            did.push_back(student);
        } else {
            didnt.push_back(student);
        }
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
    write_analysis(cout, "median of homework turned in", 
        optimistic_median_analysis, did, didnt);

    return 0;
}
