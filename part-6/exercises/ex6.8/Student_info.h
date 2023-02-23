#ifndef GUARD_Student_info_h
#define GUARD_Student_info_h

#include <vector>
#include <string>
#include <istream>

struct Student_info {
    std::string name;
    double midterm, final;
    std::vector<double> homework;
};

typedef std::vector<Student_info> Student_group;

bool compare(const Student_info&, const Student_info&);
std::istream& read_hw(std::istream&, std::vector<double>&);
std::istream& read(std::istream&, Student_info&);
Student_group extract_students(Student_group&, bool criteria(const Student_info&));
bool did_all_hw(const Student_info&);
bool midterm_higher_than_final(const Student_info& s);

#endif
