#ifndef _KEL_Q_VECTOR_H_
#define _KEL_Q_VECTOR_H_

#include <cstddef>
#include <iostream>

template<class T>
class QueueVector
{
public:
    QueueVector();
    ~QueueVector();

    void enqueue(const T &element);

    T dequeue();

    bool is_empty() const;

    void print() const;


private:
    void reserve(std::size_t new_capacity);
    // How large the array is
    std::size_t m_capacity;
    // How many elements are in the array
    std::size_t m_size;

    T* m_array;
};

#include "QueueVector.tpp"


#endif //_KEL_Q_VECTOR_H_