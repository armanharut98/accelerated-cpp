#include "median.h"
#include "Student_info.h"

using std::vector;  using std::istream;

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

istream& read(istream& is, Student_info& s) {
    // read and store the student's name and midterm and final exam grades
    is >> s.name >> s.midterm >> s.final;
    read_hw(is, s); // read and store all the student's homework grades
    return is;
}

// read homework grades from an input stream into a `vector'
istream& read_hw(istream& in, Student_info& s) {
    if (in) {
        // get rid of previous contents
        vector<double> hw;
        // read homework grades
        double x;
        while (in >> x)
            hw.push_back(x);

        s.homework = median(hw);

        // clear the stream so that input will work for the next student
        in.clear();
    }
    return in;
}
