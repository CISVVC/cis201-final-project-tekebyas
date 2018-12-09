#include "index.h"

void Index::add_word(Word word)
{
    for(int i=0; i < m_index.size(); i++)
    {
        if(word.get_word() == m_index[i].get_word())
        {
            int position = word.get_lines()[0]; // 0 because the word being entered is singular
            // when it is added to the vector below it becomes the full object with multiple lines
            m_index[i].add_word(position);
            return;
        }
    }
    m_index.push_back(word); // if the word is not found in the list of unique words, it is added
}

std::ostream& Index::print(std::ostream& o)
{
    for(int i=0; i < m_index.size(); i++)
    {
        o << m_index[i].get_word();
        o << " : ";
        o << m_index[i].get_count();
        o << " : ";
        for(int j=0; j < m_index[i].get_lines().size(); j++)
        {
            o << m_index[i].get_lines()[j]; // unsure if this works
            if(j != m_index[i].get_lines().size()-1)
            {
                o << ", ";
            }
        }
    }
}
