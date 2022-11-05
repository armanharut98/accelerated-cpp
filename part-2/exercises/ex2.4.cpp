#include <iostream>
#include <string>

// say what standard-library names we use
using std::cin;  using std::endl;
using std::cout; using std::string;

int main() {
    // ask for the person's name
    cout << "Please enter your name: ";

    // read the name
    string name;
    cin >> name;

    // build the message that we intend to write
    string greeting = "Hello, " + name + "!";

    // the number of blanks surrounding the greeting
    const int padding = 1;

    // build the blank lines surrounding the greeting
    string::size_type spaces_length = greeting.size() + padding * 2;
    string spaces(spaces_length, ' ');

    // the number of rows and columns to write
    int rows = padding * 2 + 3;
    const string::size_type columns = greeting.size() + padding * 2 + 2;

    // write a blank line to separate the output from the input
    cout << endl;

    // write "rows" rows of output
    // invariant: we have written "r" rows so far
    for (int r = 0; r < rows; ++r) {
        string::size_type c = 0;

        // invariant: we have written "c" characters so far in the current row
        while (c != columns) {
            // are we on the border
            if (r == 0 || r == rows - 1 || c == 0 || c == columns - 1) {
                    cout << "*";
                    ++c;
            } else {
                // is it time to write the greeting?
                if (r == padding + 1 && c == 1) {
                    cout << string(padding, ' ') << greeting << string(padding, ' ');
                    c += greeting.size() + padding * 2;
                } else {
                    cout << spaces;
                    c += spaces_length;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
