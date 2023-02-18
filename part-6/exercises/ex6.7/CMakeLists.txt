project(extract-students)

add_executable(main main.cpp analysis.cpp average.cpp grade.cpp median.cpp Student_info.cpp)
add_executable(analysis run_analysis.cpp analysis.cpp average.cpp grade.cpp median.cpp Student_info.cpp)
add_executable(test performance_test.cpp analysis.cpp average.cpp grade.cpp median.cpp Student_info.cpp)

