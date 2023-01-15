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

    extract_fails(students);

    for (int i = 0; i < students.size(); ++i) {
        cout << students[i].name << endl;
    }

    cout << students.size() << endl;

    duration = (std::clock() - start) / (double) CLOCKS_PER_SEC;

    cout << duration << endl;
    return 0;
}
