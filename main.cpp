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

std::vector<std::string> get_lines(std::istream& input);
std::vector<Word> get_words(std::vector<std::string> lines);

int main(int argc, char *argv[])
{
    std::ifstream input;
    std::string filename = argv[1];
    input.open(filename.c_str());
    std::vector<std::string> Lines = get_lines(input);
    input.close();
    std::cout << "Working" << std::endl;
    return 0;
}

std::vector<std::string> get_lines(std::istream& input)
{
    // set a string equal to every word leading up to '\n'
    // add string to vector
    // return vector
}

std::vector<Word> get_words(std::vector<std::string> lines)
{
    // read until whitespace
    // create Word object
    // add Word object to vector
    // return vector of Words
}
