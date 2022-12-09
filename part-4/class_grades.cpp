#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::cin;     using std::cout;
using std::vector;  using std::string;
using std::sort;    using std::max;
using std::istream; using std::endl;
using std::setprecision;
using std::streamsize;
using std::domain_error;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
};

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

// compute a student's overall grade from midterm and final exam grades and homework grade
double grade(double midterm, double final, double homework) {
    return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();

    if (size == 0) 
        throw domain_error("median of an empty array");
    
    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid - 1] + vec[mid]) / 2 : vec[mid];
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

// read homework grades from an input stream into a vector<double>
istream& read_hw(istream& in, vector<double>& hw) {
    if (in) {
        // get rid of previous contents 
        hw.clear();

        // read homework grades 
        double x;
        while (in >> x)
            hw.push_back(x);

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

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    // read and store all the records, and find the length of the longest name
    while (read(cin, record)) {
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    // alphabetize the records
    sort(students.begin(), students.end(), compare);

    for (vector<Student_info>::size_type i = 0; i != students.size(); ++i) {
        // write the name, padded on the right to maxlen + 1 characters
        cout << students[i].name << string(maxlen + 1 - students[i].name.size(), ' ');

        // compute and write the grade
        try {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec);
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    return 0;
}
