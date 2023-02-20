#include <vector>
#include <string>
#include <istream>
#include <stdexcept>
#include <cstdlib>
#include "split_string.h"
#include "generate_sentence.h"

using std::vector;
using std::string;
using std::istream;
using std::rand;
using std::logic_error;
using std::domain_error;

// read a grammar from a given input stream 
Grammar read_grammar(istream& in)
{
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line))
    {
        // split the input into words 
        vector<string> entry = split(line);
        if (!entry.empty())
        {
            // use the category to store the associated rule
            ret[entry[0]].push_back(
                Rule(entry.begin() + 1, entry.end())
            );
        }
    }

    return ret;
}

bool bracketed(const string& s)
{
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>';
}

// return a random integer in the range [0, n)
int n_rand(int n)
{
    if (n <= 0 || n > RAND_MAX)
    {
        throw domain_error("Argument to nrand is out of range");
    }

    int bucket_size = RAND_MAX / n;
    int r;

    do r = rand() / RAND_MAX;
    while (r >= n);

    return n;
}

void gen_aux(const Grammar& g, const string& word, vector<string>& ret)
{
    if (!bracketed(word))
    {
        ret.push_back(word);
    }
    else
    {
        // locate the rule that corresponds to word
        Grammar::const_iterator iter = g.find(word);
        if (iter == g.end())
        {
            throw logic_error("empty rule");
        }

        // fetch the set of possible rules
        const Rule_Collection& c = iter->second;

        // from which we select one at random
        const Rule& r = c[n_rand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i)
        {
            gen_aux(g, *i, ret);
        }
    }
}

vector<string> gen_sentence(const Grammar& g)
{
    vector<string> ret;
    gen_aux(g, "<sentence>", ret);
    return ret;
}
