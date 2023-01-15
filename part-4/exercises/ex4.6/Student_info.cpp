#include "Student_info.h"
#include <stdexcept>
#include "grade.h"

using std::vector;    using std::istream;
using std::domain_error;

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
    if (is >> s.name) {
        double midterm, final;
        vector<double> homework;
 
        // read and store the student's midterm and final exam grades
        is >> midterm >> final;
        
        // read and store all the student's homework grades
        read_hw(is, homework);
 
        try {
            s.final_grade = grade(midterm, final, homework);
        } catch(domain_error e) {
            s.final_grade = -1;
        }
    }
    return is;
}
