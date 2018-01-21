#ifndef _KEL_S_LINKED_LIST_H_
#define _KEL_S_LINKED_LIST_H_

#include <cstddef> // std::size_t
#include <iostream> // std::cout, std::endl

typedef struct Node
{  
    int data;
    // Pointer to the next Node
    Node *next;
}Node;

class SinglyLinkedList
{
public:
    SinglyLinkedList();
    ~SinglyLinkedList();

    void push_back(Node* new_node);

    void pop_back();

    void push_head(Node* new_node);

    void pop_head();

    void insert(Node* new_node, unsigned int position);

    void remove(unsigned int position);

    Node* get_head() const;

    Node* get_tail() const;

    std::size_t get_size() const;

    bool is_empty() const;

    Node* get_node(unsigned int position) const;

    void print() const;

private:
    Node *head;
    Node *tail;
    std::size_t size;
};

#endif //_KEL_S_LINKED_LIST_H_