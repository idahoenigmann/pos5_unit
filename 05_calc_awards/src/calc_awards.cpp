//
// Created by ida on 03.10.19.
//

#include <iostream>
#include <vector>
#include <string>

#include "calc_awards.h"

using namespace std;

namespace calc_awards {
    vector<vector<string>> calc_awards(vector <vector<string>> data) {
        vector<vector<string>> res{};

        for (vector<string> record : data) {
            int sum{};
            int cnt{};
            bool five{};
            bool four{};
            for (string note : record) {
                try {
                    if (note == "5") {
                        five = true;
                    } else if (note == "4") {
                        four = true;
                    }
                    sum += std::stoi(note);
                } catch (...) {

                }
                cnt++;
            }

            if (five) {
                record.push_back("nicht bestanden");
            } else if (!four && ((static_cast<double>(sum)/cnt) <= 1.5)) {
                record.push_back("mit ausgezeichnetem Erfolg bestanden");
            } else if (!four && ((static_cast<double>(sum)/cnt) <= 2)) {
                record.push_back("mit gutem Erfolg bestanden");
            } else {
                record.push_back("bestanden");
            }

            res.push_back(record);
        }
        return res;
    }
}