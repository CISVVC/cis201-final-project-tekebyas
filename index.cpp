/*
    Name: Teke Byas
    File: index.cpp
    Date of Creation: Friday, December 7, 2018
    Description: This file implements the functions used to create an index of the words found
        in a given file
*/

#include "index.h"
#include <iomanip>
#include <cctype>

Index::Index(std::ifstream& input)
{
    std::vector<std::string> lines;
    std::string line;

    while(!input.eof())
    {
        std::getline(input,line); // getline clears the "line" string automatically
        format(line);
        // "lines" is used as a buffer to break the entire file into individual lines and keep a line count
        lines.push_back(line);
    }

    std::vector<Word> buffer = get_words(lines); // buffer used to filter input through add_word

    for(int i=0; i < buffer.size(); i++)
    {
        // add_word function is called rather than just pushing each word onto the vector
        add_word(buffer[i]); // add_word will make sure no duplicate words appear on the m_index vector
    }
}

std::string Index::format(std::string& line)
{
    std::string formatted_line;

    for(int i=0; i < line.size(); i++)
    {
        line[i] = tolower(line[i]);
        if( !( (line[i] >='a' && line[i] <='z') || line[i] == ' ') )
        {
            line.erase( line.begin()+i );
            i--; // iterator has to be backed up one position else it will skip the next character
        }
        if((line[i] >= 'a' && line[i] <= 'z') || line[i] == ' ')
        {
            formatted_line += line[i];
        }
    }

    return formatted_line;
}

std::vector<Word> Index::get_words(const std::vector<std::string>& lines)
{
    std::vector<Word> words;
    std::string current_line, current_word;
    for(int line_count = 0; line_count < lines.size(); line_count++) // iterate through every line given
    {
        current_line = lines[line_count]; // grabs one line at a time
        current_line += ' '; // adds whitespace to the end of every line so that the end of each word can be determined
        for(int pos = 0; pos < current_line.size(); pos++) // iterate through every character of the line
        {
            if( !(is_whitespace( current_line[pos] ) ) )
            {
                current_word += current_line[pos];
            }
            if(current_word.size() != 0) // ensures double spaces or '\n' '\t' combinations won't make it onto the vector
            {
                if( is_whitespace( current_line[pos] ) ) // uses whitespace to determine the end of a word
                {
                    words.push_back( Word(current_word, line_count+1) );
                    current_word += current_line[pos]; // clears whitespace after word
                    current_word = ""; // the current word must be reset to blank
                }
            }
        }
    }
    return words;
}

bool Index::is_whitespace(const char c)
{
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

void Index::add_word(Word word)
{
    for(int i=0; i < m_index.size(); i++)
    {
        if(word.get_word() == m_index[i].get_word())
        {
            int position = word.get_lines()[0]; // 0 because the word being entered is singular
            // when it is added to the vector below it becomes the full object with multiple lines
            m_index[i].add_word(position);
            return; // returns here so that the word won't be pushed onto the vector if it is already there
        }
    }
    m_index.push_back(word); // if the word is not found in the list of unique words, it is added
}

std::ostream& Index::print(std::ostream& o)
{
    const int FIRST_COLUMN = 16; // the space given for the length of words
    const int SECOND_COLUMN = 7; // the space given between the count and line numbers

    o << std::setw(FIRST_COLUMN) << std::left << "Word";
    o << std::setw(SECOND_COLUMN) << std::left << "Count";
    o << "Line(s)";
    o << '\n';
    for(int i=0; i < m_index.size(); i++)
    {
        o << std::setw(FIRST_COLUMN);
        o << m_index[i].get_word();
        o << std::setw(SECOND_COLUMN);
        o << m_index[i].get_count();
        for(int j=0; j < m_index[i].get_lines().size(); j++)
        {
            o << m_index[i].get_lines()[j]; // I haven't tried this before, but I like the concept, tell me if it is bad practice
            if(j != m_index[i].get_lines().size()-1) // used to separate line numbers with a ',' but without a dangling comma
            {
                o << ", ";
            }
        }
        o << '\n';
    }
}
