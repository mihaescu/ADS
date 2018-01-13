#include "HashMap.h"
#include <climits>

HashTable::~HashTable()
{
    delete[] m_items;
}

HashTable::HashTable(int size): m_size(size)
{
    m_items = new HashEntry*[m_size];
    for(int i = 0; i < m_size; i++)
        m_items[i] = nullptr;
}

int HashTable::hashFunction(int value) const
{
    return value % m_size;
}

HashEntry::~HashEntry()
{
    HashEntry * it = m_nextCollision;
    while(it != nullptr)
    {
        HashEntry * next = it->m_nextCollision;
        delete it;
        it = next;
    }
}

void HashTable::addEntry(int value)
{
    int key = hashFunction(value);
    if(m_items[key] == nullptr)
    {
        m_items[key] = new HashEntry(value);
    }
    else
    {
        HashEntry * iter = m_items[key];
        while(iter->m_nextCollision != nullptr)
        {
            iter = iter->m_nextCollision;
        }
        iter->m_nextCollision = new HashEntry(value);
    }
}

int HashTable::findShortest() const
{
    int min = INT_MAX;
    for(int i = 0 ; i < m_size; i++)
    {
        if(m_items[i] != nullptr)
        {
            int count = 1;
            HashEntry * iter = m_items[i]->m_nextCollision;
            while(iter != NULL)
            {
                iter = iter->m_nextCollision;
                count++;
            }
            if(count < min)
                min = count;
        }
    }
    return min;
}

int HashTable::findLongest() const
{
    int max = INT_MIN;
    for(int i = 0 ; i < m_size; i++)
    {
        if(m_items[i] != nullptr)
        {
            int count = 1;
            HashEntry * iter = m_items[i]->m_nextCollision;
            while(iter != NULL)
            {
                iter = iter->m_nextCollision;
                count++;
            }
            if(count > max)
                max = count;
        }
    }
    return max;
}