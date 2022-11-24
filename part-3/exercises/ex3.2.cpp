#include <ios>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

using std::cin;     using std::cout;
using std::vector;  using std::endl;
using std::sort;    using std::streamsize;
using std::setprecision;

int main() {
    cout << "Please enter integers: " << endl;

    vector<double> nums;
    vector<double> nums1;
    vector<double> nums2;
   
    int x;

    while (cin >> x) 
        nums.push_back(x);

    if (nums.size() == 0) {
        cout << endl << "You must enter integers. "
                "Please try again." << endl;
        return 1;
    }

    sort(nums.begin(), nums.end());

    typedef vector<int>::size_type vec_sc;
    vec_sc size = nums.size();
    int mid = size / 2;

    double q2 = size % 2 == 0 ? (nums[mid] + nums[mid - 1]) / 2
                              : nums[mid];

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] < q2) {
            nums1.push_back(nums[i]);
        } else if (nums[i] > q2) {
            nums2.push_back(nums[i]);
        }
    }

    size = nums1.size();
    mid = size / 2;

    double q1 = size % 2 == 0 ? (nums1[mid] + nums1[mid - 1]) / 2
                              : nums1[mid];

    size = nums2.size();
    mid = size / 2;

    double q3 = size % 2 == 0 ? (nums2[mid] + nums2[mid - 1]) / 2
                              : nums2[mid];

    streamsize prec = cout.precision();
    cout << "The quartiles are: " << setprecision(4) << q1 << " " << q2 << " " << q3 << setprecision(prec) << endl;

    return 0;
}
