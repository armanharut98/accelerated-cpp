#include <vector>
#include <map>
#include <algorithm>
#include <istream>
#include <iostream>
#include <iomanip>
#include <stdexcept>

using std::vector;      using std::cout;
using std::sort;        using std::cin;
using std::max;         using std::endl;
using std::istream;     using std::domain_error;
using std::string;      using std::setprecision;
using std::streamsize;  
using std::map;

struct Student_info {
    string name;
    double midterm, final;
    vector<double> homework;
}; // note the semicolon it's required

bool compare(const Student_info& x, const Student_info& y) {
    return x.name < y.name;
}

// compute the median of a vector<double>
// note that calling this function copies the entire argument vector
double median(vector<double> vec) {
    typedef vector<double>::size_type vec_sz;

    vec_sz size = vec.size();
    if (size == 0) {
        throw domain_error("median of an empty vector");
    }

    sort(vec.begin(), vec.end());

    vec_sz mid = size / 2;

    return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}

double grade(double midterm, double final, double homework) {
    return midterm * 0.2 + final * 0.4 + homework * 0.4;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us
double grade(double midterm, double final, const vector<double>& hw) {
    if (hw.size() == 0) {
        throw domain_error("student has done no homework");
    }
    return grade(midterm, final, median(hw));
}

double grade(const Student_info& s) {
    return grade(s.midterm, s.final, s.homework);
}

// read homework grades from an input stream into a vector<double>
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

char get_letter_grade(double grade) {
    if (grade < 0 || grade > 100) {
        throw domain_error("invalid grade passed");
    }

    char ret;
    static const map<char, std::pair<double, double>> grade_ranges = {
        {'A', {90., 100.}},
        {'B', {80., 89.99}},
        {'C', {70., 79.99}},
        {'D', {60., 69.99}},
        {'F', {0., 60.}},
    };

    for (map<char, std::pair<double, double>>::const_iterator iter = grade_ranges.begin();
            iter != grade_ranges.end(); ++iter)
    {
        if (grade >= iter->second.first && grade <= iter->second.second)
        {
            ret = iter->first;
        }
    }

    return ret;
}

int main() {
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;
    map<char, int> grade_range_counter;

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
            char letter_grade = get_letter_grade(final_grade);
            ++grade_range_counter[letter_grade];
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade << setprecision(prec) << ": " << letter_grade;
        } catch (domain_error e) {
            cout << e.what();
        }

        cout << endl;
    }

    map<char, int>::const_iterator iter = grade_range_counter.begin();
    while (iter != grade_range_counter.end())
    {
        cout << iter->first << ": " << iter->second << endl;
        ++iter;
    }

    return 0;
}
