#include <iostream>
#include <queue>
#include <time.h>
#include <fstream>
using namespace std;

class MinHeap
{
public:
    MinHeap( int x_ = 0, int y_ = 0, int lenght_ = 0, int height_ = 0,int type_ = 0) :
    x( x_ ), y( y_ ), lenght( lenght_ ), height( height_ ), type(type_) { }
   
	int x,y,lenght,height,type;
};

inline bool operator>( const MinHeap& lhs, const MinHeap& rhs ) 
{
	return lhs.x > rhs.x;
};

inline ostream& operator<<( ostream& os, const MinHeap& c ) 
{
	os << c.x << " " << c.y << " " << c.lenght << " "<<c.height << " "<<c.type;
    return os;
};