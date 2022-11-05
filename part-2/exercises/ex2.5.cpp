#include <iostream>
#include <string>

using std::string;  using std::endl;
using std::cout;    using std::cin;

int main() {
   cout << "Please enter a shape: ";

    string shape;
    cin >> shape;

    cout << endl;

    string::size_type columns;
    string::size_type rows;

    if (shape ==  "square" || shape == "rectangle") {
        if (shape == "square") {
            rows = 5;
            columns = rows * 2;
        } else {
            rows = 5;
            columns = rows * 4;
        }
        for (int r = 0; r < rows; ++r) {
            string::size_type c = 0;

            while (c != columns) {
                if (r == 0 || r == rows - 1 || c == 0 || c == columns - 1) {
                    cout << '*';
                } else {
                    cout << " ";
                }
                ++c;
            }
            cout << endl;
        }
    } else if (shape == "triangle") {
        rows = 5;
        columns = 9;
        
        for (int r = 0; r < rows; ++r) {
            if (r == rows - 1) {
                cout << string(columns, '*');
            } else {
                string::size_type c = 0;
                while (c != columns) {
                    if (c == (columns / 2) - r || c == (columns / 2) + r) {
                        cout << "*";
                    } else {
                        cout << " ";
                    }
                    ++c;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
