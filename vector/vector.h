#ifndef _KEL_VECTOR_H_
#define _KEL_VECTOR_H_

#include <cstddef>
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
	typedef T* Iterator;

	KelVector();
	KelVector(unsigned int size);
	KelVector(unsigned int size, const T& initial);
	~KelVector();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	Iterator begin();
	const Iterator begin() const;

	Iterator end()
	const Iterator end() const;

	T& front();
	const T& front() const;
	
	T& back();
	const T& back() const;

	std::size_t capacity() const;
	std::size_t size() const;

	void push_back(const T& element);

private:
	// How large the array is
	std::size_t capacity;
	// How many elements are in the array
	std::size_t size;
	// Pointer to the array
	T *array;
};



#endif