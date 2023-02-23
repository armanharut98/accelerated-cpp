#ifndef GUARD_analysis_h
#define GUARD_analysis_h

#include <ostream>
#include <string>
#include "Student_info.h"

void write_analysis(std::ostream&, const std::string&,
                    double grading_policy(const Student_info&),
                    const Student_group&,
                    const Student_group&);

#endif
