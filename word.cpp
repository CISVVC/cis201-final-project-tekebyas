/*
    Name: Teke Byas
    File: word.cpp
    Date of Creation: Friday, December 7, 2018
    Description: This file implements the functions used in creating a Word object that will know
        what the word is, where it was found, and how many times it was found
*/

#include "word.h"

Word::Word(std::string word, int line)
{
    m_word = word;
    m_lines.push_back(line);
    m_count = 1;
}

void Word::add_word(int line)
{
    m_lines.push_back(line);
    m_count++;
}

std::string Word::get_word() const
{
    return m_word;
}

std::vector<int> Word::get_lines() const
{
    return m_lines;
}

int Word::get_count() const
{
    return m_count;
}
