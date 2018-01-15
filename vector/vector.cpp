#include "vector.h"

template<class T>
KelVector<T>::KelVector()
	: size(0)
	, capacity(0)
	, array(new T*)
{
}

template<class T>
T& KelVector<T>::operator[](unsigned int index)
{
	// Dynamic range checking
	assert ((index >= 0) && (index < size));
	return array[index];
}

template<class T>
typename KelVector<T>::Iterator KelVector<T>::begin()
{
	return array;
}

template<class T>
const typename KelVector<T>::Iterator KelVector<T>::begin() const
{
	return array;
}

template<class T>
typename KelVector<T>::Iterator KelVector<T>::end()
{
	return array + size();
}

template<class T>
const typename KelVector<T>::Iterator KelVector<T>::end() const
{
	return array + size();
}

template<class T>
T& KelVector<T>::front()
{
	return array[0];
}

template<class T>
const T& KelVector<T>::front() const
{
	return array[0];
}

template<class T>
T& KelVector<T>::back()
{
	return array[size - 1];
}

template<class T>
const T& KelVector<T>::back() const
{
	return array[size - 1];
}

template<class T>
std::size_t KelVector<T>::capacity() const
{
	return capacity;
}

template<class T>
std::size_t KelVector<T>::size() const
{
	return size;
}

template<class T>
void KelVector<vector>::push_back(const T& element)
{
	array[size++] = element;
}

