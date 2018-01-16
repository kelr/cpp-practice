#ifndef _KEL_VECTOR_H_
#define _KEL_VECTOR_H_

#include <cstddef>
#include <assert.h>
/*
So, this vector has to satisfy some requirements to be a real boy:

vector()        O(1)
vector(n, x)    O(n)
size()          O(1)
v[i]            O(1)
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
	KelVector(const KelVector<T> & other_vector);
	~KelVector();

	T& operator[](unsigned int index);
	const T& operator[](unsigned int index) const;

	KelVector<T>& operator=(const KelVector<T> &);

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


private:
	// How large the array is
	std::size_t m_capacity;
	// How many elements are in the array
	std::size_t m_size;
	// Pointer to the array
	T* m_array;
};

template<class T>
KelVector<T>::KelVector()
	: m_size(0)
	, m_capacity(0)
	, m_array(0)
{
}

template<class T>
KelVector<T>::KelVector(unsigned int size)
{
	m_size = size;
	m_capacity = size;
	m_array = new T[size];
}

template<class T>
KelVector<T>::KelVector(unsigned int size, const T& initial)
{
	m_size = size;
	m_capacity = size;
	m_array = new T[size];
	for(int i = 0; i < size; i++)
	{
		m_array[i] = initial;
		T();
	}
}

template<class T>
KelVector<T>::KelVector(const KelVector<T> & other_vector)
{
	m_size = other_vector.m_size;
	m_capacity = other_vector.m_capacity;

	//Copy over the elements
	m_array = new T[m_size];
	for(int i = 0; i < m_size; i++)
	{
		m_array = other_vector[i];
	}
}

template<class T>
KelVector<T>::~KelVector()
{
	delete[] m_array;
}

template<class T>
T& KelVector<T>::operator[](unsigned int index)
{
	// Some dynamic range checking
	assert((index >= 0) && (index < m_size));
	return m_array[index];
}

template<class T>
KelVector<T>& KelVector<T>::operator=(const KelVector<T> & other_vector)
{
	delete[] m_array;
	//Copy the size and capacity
	m_size = other_vector.m_size;
	m_capacity = other_vector.m_capacity;

	//Copy over the elements
	m_array = new T[m_size];
	for(int i = 0; i < m_size; i++)
	{
		m_array = other_vector[i];
	}
	return *this;
}

template<class T>
typename KelVector<T>::Iterator KelVector<T>::begin()
{
	return m_array;
}

template<class T>
const typename KelVector<T>::Iterator KelVector<T>::begin() const
{
	return m_array;
}

template<class T>
typename KelVector<T>::Iterator KelVector<T>::end()
{
	return m_array + size();
}

template<class T>
const typename KelVector<T>::Iterator KelVector<T>::end() const
{
	return m_array + size();
}

template<class T>
T& KelVector<T>::front()
{
	return m_array[0];
}

template<class T>
const T& KelVector<T>::front() const
{
	return m_array[0];
}

template<class T>
T& KelVector<T>::back()
{
	return m_array[m_size - 1];
}

template<class T>
const T& KelVector<T>::back() const
{
	return m_array[m_size - 1];
}

template<class T>
const std::size_t KelVector<T>::capacity() const
{
	return m_capacity;
}

template<class T>
const std::size_t KelVector<T>::size() const
{
	return m_size;
}

template<class T>
void KelVector<T>::push_back(const T& element)
{
	m_array[m_size++] = element;
}

#endif