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
#include<sstream>
#include<string>
#include<vector>
#include<cctype>
#include "index.h"

std::vector<std::string> get_lines(std::istream& input);
std::string format(std::string line);
std::vector<Word> get_words(std::vector<std::string> lines);
void add_to_index(std::vector<Word> words, Index& index);

int main(int argc, char *argv[]) // should be run in format: "./main [input file] [output file (optional)]"
{
    std::ifstream input;
    std::string filename = argv[1]; // input file
    input.open(filename.c_str());
    std::vector<std::string> lines = get_lines(input); // add lines to a vector for use without file
    input.close();

    std::vector<Word> words = get_words(lines); // breaks each line into individual words

    Index index;
    add_to_index(words, index); // add each word to the index

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

    std::cout << "Working" << std::endl;
    return 0;
}

std::vector<std::string> get_lines(std::istream& input)
{
    std::vector<std::string> lines;
    std::string line;

    while(!input.eof())
    {
        std::getline(input,line);
        format(line);
        lines.push_back(line);
    }

    return lines;
}

std::string format(std::string line)
{
    std::string formatted_line;
    for(int i=0; i < line.size(); i++)
    {
        if(line.at(i) >= 'A' && line.at(i) <= 'Z')
        {
            line[i] = tolower(line[i]);
        }
    }

    for(int i=0; i < line.size(); i++)
    {
        if((line.at(i) > 'a' && line.at(i) < 'z') || line.at(i) == ' ')
        {
            formatted_line += line.at(i);
        }
    }

    return formatted_line;
}

std::vector<Word> get_words(std::vector<std::string> lines)
{
    std::vector<Word> words;
    std::string current_line, current_word;

    for(int i=0; i < lines.size(); i++)
    {
        current_line = lines[i];
        for(int j=0; j < current_line.size(); j++)
        {
            if(current_line[j] != ' ')
            {
                current_word += current_line[j];
            }
            else
            {
                words.push_back(Word(current_word,i));
                current_word = "";
            }
        }
    }

    return words;
}

void add_to_index(std::vector<Word> words, Index& index)
{
    for(int i=0; i < words.size(); i++)
    {
        index.add_word(words[i]);
    }
}
