//
// Created by ida on 03.10.19.
//

#ifndef STRING_UTILITIES_H
#define STRING_UTILITIES_H

#include <vector>
#include <string>

namespace string_utilities {
    std::vector <std::string> split(const std::string& s, char delimiter);
    std::string join(const std::vector <std::string>& data, char delimiter);
}

#endif //STRING_UTILITIES_H
