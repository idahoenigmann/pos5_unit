//
// Created by ida on 12.09.19.
//

#include <iostream>
#include <fstream>
#include <string.h>

#include "file_utilities.h"

using namespace std;

namespace file_utilities {
    vector <string> read_textfile(istream &file) {
        if (!file) {
            throw runtime_error("file stream is bad");
        }

        string text;
        vector <string> res{};
        while (getline(file, text)) {
            res.push_back(text);
        }
        return res;
    }

    vector <string> read_textfile(const string filename) {
        ifstream s;
        s.open(filename);
        if (s.is_open() && !s.bad() && !s.fail()) {
            vector <string> res{read_textfile(s)};
            s.close();
            return res;
        } else {
            throw runtime_error("file could not be opened.");
        }
    }

    void write_textfile(ostream &file, vector <string> lines) {
        if (!file) {
            throw runtime_error("file stream is bad");
        }

        for (auto line : lines) {
            file << line << endl;
        }
    }

    void write_textfile(const string filename, vector <string> lines) {
        ofstream s;
        s.open(filename);
        if (s.is_open() && !s.bad() && !s.fail()) {
            write_textfile(s, lines);
            s.close();
        } else {
            throw runtime_error("file could not be written.");
        }
    }
}
