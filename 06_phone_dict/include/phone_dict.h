//
// Created by ida on 12.09.19.
//

#pragma once

#include <iostream>
#include <unordered_map>

namespace phone_dict{
    class PhoneDict {
    private:
        std::unordered_map<std::string, int> dict{};

        friend std::ostream& operator<<(std::ostream&,const PhoneDict&);
        friend std::istream& operator>>(std::istream& is, PhoneDict& phoneDict);

    public:
        auto begin() { return dict.begin(); }
        auto cbegin() const { return dict.cbegin(); }
        auto end() { return dict.end(); }
        auto cend() const { return dict.cend(); }
        auto find(const std::string& s) { return dict.find(s); }
        auto erase(const std::string& s) { return dict.erase(s); }
        auto& operator[](const std::string& s) { return dict[s]; }
    };

    inline std::ostream& operator<<(std::ostream& os, const PhoneDict& phoneDict) {
        nlohmann::json dict;
        dict = phoneDict.dict;

        return os << dict << std::flush;
    }

    inline std::istream& operator>>(std::istream& is, PhoneDict& phoneDict) {
        nlohmann::json json;
        is >> json;

        for (auto& [key, value] : json.items()) {
            phoneDict[key] = value;
        }
        return is;
    }
}
