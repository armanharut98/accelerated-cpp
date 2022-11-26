#include <string>
#include <vector>
#include <ios>
#include <iostream>
#include <algorithm>
#include <iomanip>

using std::cin;     using std::cout;
using std::endl;    using std::string;
using std::vector;  using std::streamsize;
using std::setprecision;

int main() {
    vector<string> students;
    vector<double> grades;

    vector<string>::size_type student_count;
    
    cout << "Please enter the number of students: ";

    cin >> student_count;

    if (student_count == 0) {
        cout << endl << "Enter a valid number of students. "
            "Please try again" << endl;
        return 1;
    }

    for (int i = 0; i < student_count; ++i) {
        cout << "Please enter student name: " << endl;

        string student_name;
        int num_of_grades = 5;
        cin >> student_name;
        students.push_back(student_name);

        double sum = 0;
        int grade = 0;
        cout << "Please enter " << student_name << "\'s  grades" << endl;
        for (int j = 0; j < num_of_grades; ++j) {
            cin >> grade;
            sum += grade;
        }
        grades.push_back(sum / num_of_grades);
    }

    streamsize prec = cout.precision(3);
    for (int i = 0; i < students.size(); ++i) {
        cout << students[i] << ": " << grades[i] << endl;
    }
    cout.precision(prec);

    return 0;
}
