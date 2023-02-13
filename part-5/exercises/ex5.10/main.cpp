#include <string>
#include <list>
#include <iostream>
#include <algorithm>
#include "check_palindrome.h"

using std::list;
using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::max;

int main() {
    list<string> words;
    list<string> palindromes;

    string::size_type maxlen = 0;
    string longest_palindrome;

    string s;
    while (cin >> s) {
        //cout << s << endl;
        words.push_back(s);
    }

    list<string>::iterator iter1 = words.begin();
    while (iter1 != words.end()) {
        if (isPalindrome(*iter1)) {
            palindromes.push_back(*iter1);
            if ((*iter1).size() > maxlen) {
                maxlen = (*iter1).size();
                longest_palindrome = *iter1;
            }
        }
        ++iter1;
    }

    cout << "There are " << palindromes.size() << " palindromes" << endl;

    list<string>::iterator iter2 = palindromes.begin();
    while (iter2 != palindromes.end()) {
        cout << *iter2 << endl;
        ++iter2;
    }

    cout << "The longest palindrome: " << longest_palindrome << endl;

    return 0;
}
