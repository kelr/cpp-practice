#ifndef _KEL_S_LINKED_LIST_H_
#define _KEL_S_LINKED_LIST_H_

#include <cstddef> // std::size_t
#include <iostream> // std::cout, std::endl
#include <assert.h> //assert()

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
    void insert(const T &input_data, int position);

    // Remove a node at a position
    void remove(int position);

    // Get the data stored in head
    T get_head() const;

    // Get the data stored in tail
    T get_tail() const;

    // Get the number of elements in the list
    std::size_t get_size() const;

    // Is the list empty or not
    bool is_empty() const;

    // Print a pretty picture
    void print() const;

    // Get the data for an element at a position
    T get_data_at(int position) const;

    // Reverse the entire list
    void reverse();

    // Remove the node where the first instance of the data appears
    void remove_first_encounter(const T &input_data);

    // Clear all elements from the list
    void clear_list();

private:
    // Get a node at a position
    typename SinglyLinkedList<T>::Node* get_node(int position) const;
    
    struct Node
    {  
        T data;
        Node* next = nullptr;
    };

    Node* head;
    Node* tail;
    std::size_t size;
};

#include "SinglyLinkedList.tpp"

#endif //_KEL_S_LINKED_LIST_H_