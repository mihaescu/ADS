#include <vector>
#include <list>
#include <map>

class HashEntry
{
public:
    friend class HashTable;
    HashEntry(int value): m_value(value), m_nextCollision(nullptr){}
    HashEntry():m_value(0), m_nextCollision(nullptr){};
    ~HashEntry();
private:
    HashEntry * m_nextCollision;
    int m_value;
};

class HashTable
{
public:
    HashTable(int size);
    ~HashTable();
    void addEntry(int value);
    int hashFunction(int value) const;
    int findShortest() const;
    int findLongest() const;
private: 
    HashEntry **m_items;  
    int m_size;
};
