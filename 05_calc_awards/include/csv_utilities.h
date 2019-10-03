//
// Created by ida on 03.10.19.
//

#ifndef CSV_UTILITIES_H
#define CSV_UTILITIES_H

#include <vector>

namespace csv_utilities {
    std::vector<std::vector<std::string>>csv_reader(std::vector<std::string>lines, std::vector<std::string>&header);
    std::vector<std::string>csv_writer(std::vector<std::vector<std::string>>data, std::vector<std::string>header);
}

#endif //CSV_UTILITIES_H
