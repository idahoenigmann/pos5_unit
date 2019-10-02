//
// Created by ida on 10.09.19.
//

#include <iostream>

#include "file_utilities.h"

using namespace std;

int main(int argc, char *argv[]) {
    for(int i{0}; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << endl;

    auto res = read_textfile("asdf.txt");
    for (auto s : res) {
        cout << s << endl;
    }

    return 0;
}
