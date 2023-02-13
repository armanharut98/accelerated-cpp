#include <vector>
#include <string>
#include <iostream>
#include "url_finder.h"

using std::vector;
using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::endl;

int main() {
    string input; 

    string line;
    while (getline(cin, line))
        input += line + "\n";

    vector<string> urls = find_urls(input);

    vector<string>::const_iterator iter = urls.begin();
    while (iter != urls.end()) {
        cout << *iter << endl;
        iter++;
    }

    return 0;
}