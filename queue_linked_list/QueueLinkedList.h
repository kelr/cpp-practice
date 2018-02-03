#ifndef _KEL_Q_LINKED_LIST_
#define _KEL_Q_LINKED_LIST_

#include <iostream>

template <class T>
class QueueLinkedList
{
public:
    QueueLinkedList();
    ~QueueLinkedList();

    void enqueue(const T &data);

    void dequeue();

    bool is_empty() const;

    void print();

private:
    struct Node
    {
        T data;
        Node* next = nullptr;
    };

    Node* head;
    Node* tail;
};

#include "QueueLinkedList.tpp"

#endif //_KEL_Q_LINKED_LIST_