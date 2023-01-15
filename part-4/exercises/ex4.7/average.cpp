#include <vector>

using std::vector;

double average(const vector<double>& vec) {
    vector<double>::size_type size = vec.size();

    double sum = 0;
    for (vector<double>::size_type i = 0; i < size; ++i) {
        sum += vec[i];
    }

    return sum / size;
}
