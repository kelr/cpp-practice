#ifndef _KEL_VECTOR_H_
#define _KEL_VECTOR_H_

#include <iostream>
#include <cstddef>
#include <assert.h>
/*
So, this vector has to satisfy some requirements to be a real boy:

vector()        O(1)
vector(n, x)    O(n)
size()          O(1)
v[i]            O(1)
push_back(x)    O(1) (amortized!)
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
	KelVector(std::size_t size);
	KelVector(std::size_t size, const T& initial);
	KelVector(const KelVector<T> & other_vector);
	~KelVector();

	T& operator[](std::size_t index);
	const T& operator[](std::size_t index) const;
	KelVector<T> & operator=(const KelVector<T> &);

	void reserve(std::size_t new_size);

	bool is_empty() const;

	Iterator begin();
	const Iterator begin() const;
	Iterator end();
	const Iterator end() const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;

	const std::size_t capacity() const;
	const std::size_t size() const;

	void push_back(const T& element);
	void pop_back();

	void clear();
	void print_all();

private:
	// How large the array is
	std::size_t m_capacity;
	// How many elements are in the array
	std::size_t m_size;
	// Pointer to the array
	T* m_array;
};

#include "vector.tpp"

#endif