#include <string>

using std::string;

bool charExists(char c, string s) {
    for (string::size_type i = 0; i != s.size(); ++i) {
        if (s[i] == c) {
            return true;
        }
    }
    return false;
}

bool isAscender(char c) {
    string ascenders = "bdfhklt";

    for (string::size_type i = 0; i != ascenders.size(); ++i) {
        if (ascenders[i] == c) {
            return true;
        }
    }

    return false;
}

bool isDescender(char c) {
    string descender = "gjpqy";

    for (string::size_type i = 0; i != descender.size(); ++i) {
        if (descender[i] == c) {
            return true;
        }
    }

    return false;
}
