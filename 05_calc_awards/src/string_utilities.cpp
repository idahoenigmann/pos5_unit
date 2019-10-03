//
// Created by ida on 03.10.19.
//

#include <vector>
#include <string>
#include <sstream>

#include "string_utilities.h"

using namespace std;

namespace string_utilities {
    vector <string> split(const string& s, char delimiter) {
        vector <string> tokens;
        string token;
        istringstream token_stream(s);
        while (getline(token_stream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }

    string join(const vector <string> &data, char delimiter) {
        string res{};

        for (long unsigned int i{0}; i < data.size() - 1; i++) {
            auto token = data[i];
            res += token + delimiter;
        }
        res += data[data.size() - 1];
        return res;
    }
}
