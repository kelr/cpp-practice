#ifndef _KEL_VECTOR_H_
#define _KEL_VECTOR_H_

#include "stdio.h"
/*
So, this vector has to satisfy some requirements to be a real boy:

vector()        O(1)
vector(n, x)    O(n)
size()          O(1)
v[ i ]          O(1)
push_back(x)    O(1)
pop_back        O(1)
insert          O(size())
erase           O(size())
front, back     O(1)
*/

template <class T> 
class KelVector
{
public:

	KelVector();
	KelVector(unsigned int size);
	KelVector(unsigned int size, const T& initial);
	~KelVector();

	T& operator[](unsigned int index);

private:
	// How large the array is
	unsigned int capacity;
	// How many elements are in the array
	unsigned int size;
	// Pointer to the array
	T *array;
};



#endif