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

void usage();

int main(int argc, char *argv[]) // should be run in format: "./main [input file] [output file (optional)]"
{
    if(argc > 1 && argc < 4) // makes sure there are two or three inputs as that is all that can be handled
    {
        std::string filename = argv[1];
        std::ifstream input;
        input.open(filename.c_str());

        if( !input.is_open() )
        {
            std::cout << "Error opening file: " << filename << std::endl;
            return 1;
        }

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
            usage();
        }
    }
    else
    {
        usage();
    }

    return 0;
}

/*
    Returns a message to the command-line showing how to properly run the executable
*/
void usage()
{
    std::cout << "Error:" << std::endl;
    std::cout << "./main [input file] [output destination]" << std::endl;
    std::cout << "  --Blank output destination prints output on command-line interface" << std::endl;
}
