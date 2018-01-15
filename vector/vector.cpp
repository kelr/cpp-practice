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
void KelVector<vector>::push_back(const vector& element)
{
	array[size] = element
	size++;
}

