#include <vector>
#include <string>
#include <iostream>
#include "generate_sentence.h"

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main() {
    // generate the sentence
    vector<string> sentence = gen_sentence(read_grammar(cin));

    // write the first word, if any
    vector<string>::const_iterator iter = sentence.begin();
    if (!sentence.empty())
    {
        cout << *iter;
        ++iter;
    }

    // write the rest of the words, each preceded by a space 
    while (iter != sentence.end())
    {
        cout << " " << *iter;
        ++iter;
    }

    cout << endl;

    return 0;
}