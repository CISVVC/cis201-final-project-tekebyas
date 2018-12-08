#include "index.h"

void Index::add_word(Word word, int line)
{
    for(int i=0; i < m_index.size(); i++)
    {
        if(word.get_word() == m_index[i].get_word())
        {
            m_index[i].add_word(line);
            return;
        }
    }
    m_index.push_back(word);
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
            o << m_index[i].get_lines()[j]; // unsure if this works, replace even if it does
            if(j != m_index[i].get_lines().size()-1)
            {
                o << ", ";
            }
        }
    }
}
