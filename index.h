#ifndef INDEX_H
#define INDEX_H

#include "word.h"
#include<vector>
#include<fstream>

class Index
{
public:
    Index(std::ifstream& input);
    std::string format(std::string& line);
    std::vector<Word> get_words(std::vector<std::string>& lines);
    bool is_whitespace(char c);
    void add_word(Word word);
    std::ostream& print(std::ostream& o);
private:
    std::vector<Word> m_index;
};

#endif
