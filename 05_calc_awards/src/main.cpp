//
// Created by ida on 10.09.19.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <string.h>

#include "CLI11.hpp"

#include "file_utilities.h"
#include "string_utilities.h"
#include "csv_utilities.h"
#include "calc_awards.h"

using namespace std;

int main(int argc, char *argv[]) {
    CLI::App app("Calculates the awards for the given students");
    app.get_formatter()->label("OPTIONS", "Options");
    string inputStreamString;
    app.add_option("STDIN", inputStreamString, "stdin marker (must be '-')");

    string infile{};
    string outfile{};

    app.add_option("-i,--infile", infile, "The file to be processed (if ommited: stdin)");
    app.add_option("-o,--outfile", outfile, "The file to be written (if ommited: stdout)");

    CLI11_PARSE(app, argc, argv);

    vector<string> header{};

    if (infile != "" && outfile != "") {
        auto input_data = csv_utilities::csv_reader(file_utilities::read_textfile(infile), header);
        auto data_with_awards = calc_awards::calc_awards(input_data);
        header.push_back("award");
        file_utilities::write_textfile(outfile, csv_utilities::csv_writer(data_with_awards, header));
    } else if (infile != "") {
        auto input_data = csv_utilities::csv_reader(file_utilities::read_textfile(infile), header);
        auto data_with_awards = calc_awards::calc_awards(input_data);
        header.push_back("award");
        file_utilities::write_textfile(cout, csv_utilities::csv_writer(data_with_awards, header));
    } else if (outfile != "") {
        auto input_data = csv_utilities::csv_reader(file_utilities::read_textfile(cin), header);
        auto data_with_awards = calc_awards::calc_awards(input_data);
        header.push_back("award");
        file_utilities::write_textfile(outfile, csv_utilities::csv_writer(data_with_awards, header));
    } else {
        auto input_data = csv_utilities::csv_reader(file_utilities::read_textfile(cin), header);
        auto data_with_awards = calc_awards::calc_awards(input_data);
        header.push_back("award");
        file_utilities::write_textfile(cout, csv_utilities::csv_writer(data_with_awards, header));
    }

    return 0;
}
