project(class-grades)

add_executable(analysis run_analysis.cpp analysis.cpp grade.cpp median.cpp average.cpp Student_info.cpp)
add_executable(extract extract.cpp grade.cpp average.cpp median.cpp Student_info.cpp)
add_executable(test_extract test_extract.cpp grade.cpp average.cpp median.cpp Student_info.cpp)
