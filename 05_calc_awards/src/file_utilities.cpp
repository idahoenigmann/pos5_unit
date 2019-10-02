//
// Created by ida on 12.09.19.
//

#include <iostream>
#include <fstream>

#include "file_utilities.h"

using namespace std;

vector<string> read_textfile(istream& file) {
    string text;
    vector<string> res{};
    while (getline(file,text)) {    // TODO: does not stop at eof
        res.push_back(text);
    }
    return res;
}

vector<string> read_textfile(const string filename) {
    ifstream s;
    s.exceptions(ios_base::badbit | ios_base::failbit);
    s.open(filename);
    if (s.is_open() && !s.bad() && !s.fail()) {
        vector <string> res{read_textfile(s)};
        s.close();
        return res;
    } else {
        throw runtime_error("file could not be opened.");
    }
}

void write_textfile(ostream& file, vector<string> lines) {
    for (auto line : lines) {
        file << line << endl;
    }
}

void write_textfile(const string filename, vector<string> lines) {
    ofstream s;
    s.exceptions(ios_base::badbit | ios_base::failbit);
    s.open(filename);
    //if (s.is_open()) {
    write_textfile(s, lines);
    s.close();
}
