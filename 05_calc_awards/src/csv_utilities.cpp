//
// Created by ida on 03.10.19.
//

#include <vector>
#include <string>

#include "csv_utilities.h"
#include "string_utilities.h"

using namespace std;

namespace csv_utilities {
    vector<vector<string>>csv_reader(vector<string>lines, vector<string>&header) {
        vector<vector<string>> res{};
        header = string_utilities::split(lines.front(), ',');

        for (long unsigned int i{1}; i < lines.size(); i++) {
            auto line = lines[i];
            res.push_back(string_utilities::split(line, ','));
        }

        return res;
    }

    vector<string>csv_writer(vector<vector<string>>data, vector<string>header) {
        vector<string> res{};

        res.push_back(string_utilities::join(header, ','));

        for (auto line : data) {
            res.push_back(string_utilities::join(line, ','));
        }

        return res;
    }
}
