#ifndef _KEL_VECTOR_H_
#define _KEL_VECTOR_H_

#include "stdio.h"
/*
So, this vector has to satisfy some requirements. Because rasins.

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

template <class T> class kel_vector
{
public:
	// Indexing operator
	T& kel_vector<T>::operator [ ] (unsigned int i)
	{
		// Dynamic range checking
		assert ((i >= 0) && (index < size));
		return array[i];
	}



private:
	// How large the array is
	int capacity;
	// How many elements are in the array
	int size;
	// Pointer to the array
	T *array;
};



#endif