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
std::string format(std::string& line);
std::vector<Word> get_words(std::vector<std::string>& lines);
bool is_whitespace(char c);
void add_to_index(std::vector<Word>& words, Index& index);

int main(int argc, char *argv[]) // should be run in format: "./main [input file] [output file (optional)]"
{
    std::ifstream input;
    std::string filename = argv[1]; // input file
    filename += ".txt";
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

std::string format(std::string& line)
{
    std::string formatted_line;

    for(int i=0; i < line.size(); i++)
    {
        line[i] = tolower(line[i]);
        if( !( (line[i] >='a' && line[i] <='z') || line[i] == ' ') )
        {
            line[i] = ' ';
        }
        if((line[i] >= 'a' && line[i] <= 'z') || line[i] == ' ')
        {
            formatted_line += line[i];
        }
    }

    return formatted_line;
}

std::vector<Word> get_words(std::vector<std::string>& lines)
{
    std::vector<Word> words;
    std::string current_line, current_word;
    int position;
    for(int line_count = 0; line_count < lines.size(); line_count++)
    {
        current_line = lines[line_count];
        current_line += ' ';
        for(int pos = 0; pos < current_line.size(); pos++)
        {
            if( !(is_whitespace( current_line[pos] ) ) )
            {
                current_word += current_line[pos];
            }
            if(current_word.size() != 0)
            {
                if( is_whitespace( current_line[pos] ) )
                {
                    words.push_back( Word(current_word, line_count+1) );
                    current_word += current_line[pos]; // clears whitespace after word
                    current_word = "";
                }
            }
        }
    }
    return words;
}

bool is_whitespace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void add_to_index(std::vector<Word>& words, Index& index)
{
    for(int i=0; i < words.size(); i++)
    {
        index.add_word(words[i]);
    }
}
