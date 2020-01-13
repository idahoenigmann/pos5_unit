//
// Created by ida on 10.09.19.
//

#include <iostream>

#include "CLI11.hpp"
#include "json.hpp"

#include "sll.h"
#include "Dictionary.h"
#include "phone_dict.h"

using namespace std;

int main(int argc, char *argv[]) {
    CLI::App app("Stores, retrieves, and deletes phone numbers");
    app.get_formatter()->label("OPTIONS", "Options");

    string name{};
    int number{};

    auto o_name = app.add_option("NAME", name, "name to query or set");
    auto o_number = app.add_option("NUMBER", number, "phone number to set");

    string file{"phone_numbers.json"};

    auto o_f = app.add_option("-f,--file", file, "The file to be processed (default: phone_numbers.json)");
    auto o_l = app.add_flag("-l", "List the content of the phone dictionary");
    auto o_e = app.add_flag("-e", "Erase the entry for the given NAME");

    o_name->excludes(o_l);
    o_number->needs(o_name);
    o_number->excludes(o_e);
    o_f->envname("PHONE_NUMBERS_FILE");
    o_l->excludes(o_e);
    o_e->needs(o_name);
    o_e->excludes(o_l);

    CLI11_PARSE(app, argc, argv);

    phone_dict::PhoneDict phoneDict{};

    ifstream s;
    s.open(file);
    if (s.is_open() && !s.bad() && !s.fail()) {
        s >> phoneDict;
    } else {
        cout << "file " + file + " could not be opened" << endl;
        exit(1);
    }
    s.close();

    if (*o_l) {
        for (auto [key, value] : phoneDict) {
            cout << key << ": " << value << endl;
        }
    } else if (*o_e) {
        if (phoneDict.find(name) == phoneDict.end()) {
            cout << "no user " << name << endl;
            exit(1);
        }
        phoneDict.erase(name);
        cout << "name " << name << " erased" << endl;
    } else if (o_name->count() > 0) {
        if (o_number->count() > 0) {
            phoneDict[name] = number;
            cout << "number " << number << " set for " << name << endl;
        } else {
            auto element = phoneDict.find(name);
            if (element != phoneDict.end()) {
                cout << element->second << endl;
            } else {
                cout << "no user " << name << endl;
            }
        }
    }

    ofstream t;
    t.open(file);
    if (t.is_open() && !t.bad() && !t.fail()) {
        t << phoneDict << endl;
        t.close();
    } else {
        cout << "file " + file + " could not be written" << endl;
        exit(1);
    }

    return 0;
}
