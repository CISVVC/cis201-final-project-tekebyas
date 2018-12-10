/*
    Name: Teke Byas
    File: main.cpp
    Date of Creation: Friday, December 7, 2018
    Description: This program will take a file as input and return a concordance
        of every word, how many times it was found, and on what lines it was found
        in the format:
            word : count : line number, line number, etc.
 */

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "index.h"

int main(int argc, char *argv[]) // should be run in format: "./main [input file] [output file (optional)]"
{
    const std::string EXTENSION = ".txt";
    std::string filename = argv[1];
    filename += EXTENSION;
    std::ifstream input;
    input.open(filename.c_str());
    Index index(input);
    input.close();

    if(argc == 2) // no output file
    {
        index.print(std::cout); // defaults to command-line if no output file is given
    }
    else if(argc == 3) // used if an output file was given
    {
        std::ofstream output;
        std::string outfile = argv[2]; // output file
        output.open(outfile.c_str());
        index.print(output);
        output.close();
    }
    else
    {
        std::cout << "Usage:\n    -- ./main [input file] [output file (optional)]" << std::endl;
    }

    return 0;
}
