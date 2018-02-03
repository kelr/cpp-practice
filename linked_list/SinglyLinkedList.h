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

    T get_head() const;

    T get_tail() const;

    std::size_t get_size() const;

    bool is_empty() const;

    void print() const;

    T get_data_at(iterator position) const;

    void reverse();

    void remove_first_encounter(const T &input_data);


    //get_value_from_back(n) get value of node at nth position from end
    //reverse() reverse list
    //remove_value(value) remove first encounter of value

private:
    typename SinglyLinkedList<T>::Node* get_node(iterator position) const;
    
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