//
// Created by ida on 10.09.19.
//

#include <iostream>

#include "asdf.h"

using namespace std;

int main(int argc, char *argv[]) {
    for(int i{0}; i < argc; i++) {
        cout << argv[i] << " ";
    }
    cout << endl;
    return 0;
}
