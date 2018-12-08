#ifndef INDEX_H
#define INDEX_H

#include "word.h"
#include<vector>
#include<ostream>

class Index
{
public:
    void add_word(Word word);
    std::ostream& print(std::ostream& o);
private:
    std::vector<Word> m_index;
};

#endif
