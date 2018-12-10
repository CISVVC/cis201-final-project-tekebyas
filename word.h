/*
    Name: Teke Byas
    File: word.h
    Date of Creation: Friday, December 7, 2018
    Description: This file documents the functions used in creating a Word object that will know
        what the word is, where it was found, and how many times it was found
*/

#ifndef WORD_H
#define WORD_H

#include<vector>
#include<string>

class Word
{
public:
    /*
        Creates a Word object that will know the word held, the line numbers it is found on,
            and how many times it is found
        @param word = the word that was found
        @param line = on what line the word was found
    */
    Word(std::string word, int line);

    /*
        Increments the count of a word and adds the line it was found on to the vector of lines
        @param line = the line the word was found on
    */
    void add_word(int line);

    /*
        Returns the name of the word
        @return the word
    */
    std::string get_word() const;

    /*
        Returns a vector of lines where the word was found
        @return a vector of integers
    */
    std::vector<int> get_lines() const;

    /*
        Returns how many times the word was found
        @return the count
    */
    int get_count() const;
private:
    std::string m_word;
    std::vector<int> m_lines;
    int m_count;
};

#endif
