#ifndef _KEL_S_LINKED_LIST_H_
#define _KEL_S_LINKED_LIST_H_

#include <cstddef> // std::size_t
#include <iostream> // std::cout, std::endl

template <class T>
class SinglyLinkedList
{
public:
    typedef T* iterator;

    SinglyLinkedList();
    ~SinglyLinkedList();

    iterator begin();
    const iterator begin() const;

    iterator end();
    const iterator end() const;

    // Add a node to the back of the list
    void push_back(const T &input_data);

    // Remove a node from the back of the list
    void pop_back();

    // Add a node to the front of the list
    void push_head(const T &input_data);

    // Remove a node from the front of the list
    void pop_head();

    // Insert data at position
    void insert(const T &input_data, iterator position);

    void remove(iterator position);

    typename SinglyLinkedList<T>::Node* get_head() const;

    typename SinglyLinkedList<T>::Node* get_tail() const;

    std::size_t get_size() const;

    bool is_empty() const;

    typename SinglyLinkedList<T>::Node* get_node(iterator position) const;

    void print() const;


    //size() num of elements
    //erase(index) remove node at index 
    //get_value_from_back(n) get value of node at nth position from end
    //reverse() reverse list
    //remove_value(value) remove first encounter of value

private:
    struct Node
    {  
        T data;
        Node* next;
    };

    Node* head;
    Node* tail;
    std::size_t size;
};

#include "SinglyLinkedList.tpp"

#endif //_KEL_S_LINKED_LIST_H_