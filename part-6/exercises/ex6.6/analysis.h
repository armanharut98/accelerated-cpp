#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <ostream>
#include <string>
#include "Student_info.h"

double median_analysis(const Student_group&);
double average_analysis(const Student_group&);
double optimistic_median_analysis(const Student_group&);
void write_analysis(std::ostream&, const std::string&,
                    double analysis(const Student_group&),
                    Student_group did,
                    Student_group didnt);

#endif
