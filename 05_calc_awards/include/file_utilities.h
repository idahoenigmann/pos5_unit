//
// Created by ida on 12.09.19.
//

#ifndef FILE_UTILITIES_H
#define FILE_UTILITIES_H

#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> read_textfile(std::istream& file); // throws runtime_error
std::vector<std::string> read_textfile(const std::string filename); // throws runtime_error
void write_textfile(std::ostream& file, std::vector<std::string> lines); // throws runtime_error
void write_textfile(const std::string filename, std::vector<std::string> lines); // throws runtime_error

#endif //FILE_UTILITIES_H
