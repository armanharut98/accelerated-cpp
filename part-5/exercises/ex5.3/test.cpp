#include <list>
#include <vector>
#include <iostream>
#include <ctime>
#include "Student_info.h"

using std::list;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    Student_group students;

    Student_info record;
    while (read(cin, record)) {
        students.push_back(record);
    }

    std::clock_t start;
    double duration;

    start = std::clock();

    Student_group failed = extract_fails(students);

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << duration << endl;
    return 0;
}
