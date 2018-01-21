#include "SinglyLinkedList.h"

SinglyLinkedList::SinglyLinkedList()
{
    head = NULL;
    tail = NULL;
}

SinglyLinkedList::~SinglyLinkedList()
{

}

void SinglyLinkedList::push_back(Node* new_node)
{
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        new_node->next = NULL;
    }
    size++;
}

void SinglyLinkedList::pop_back()
{
    if (head == NULL)
    {
        std::cout << "There's nothing in the list to pop" << std::endl;
    }
    else
    {
        Node* current_node = head;
        Node* previous_node = head;
        while (current_node != NULL)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
        tail = previous_node;
        previous_node->next = NULL;
        previous_node = NULL;
        size--;
    }
}

void SinglyLinkedList::push_head(Node* new_node)
{
    if (head == NULL)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    size++;
}

void SinglyLinkedList::pop_head()
{
    if (head == NULL)
    {
        std::cout << "There's nothing in the list to pop" << std::endl;
    }
    else
    {
        head = head->next;
        size--;   
    }

}

// Starts from zero, which is head
void SinglyLinkedList::insert(Node* new_node, unsigned int position)
{
    Node* current_node = head;
    Node* previous_node = head;
    for (unsigned int i = 0; i < position; i++)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = new_node;
    new_node->next = current_node;
    previous_node = NULL;
    current_node = NULL;
    size++;
}

void SinglyLinkedList::remove(unsigned int position)
{
    Node* current_node = head;
    Node* previous_node = head;
    for (unsigned int i = 0; i < position; i++)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = current_node->next;
    current_node->next = NULL;
    current_node = NULL;
    previous_node = NULL;
    size--;
}

Node* SinglyLinkedList::get_head() const
{
    return head;
}

Node* SinglyLinkedList::get_tail() const
{
    return tail;
}

std::size_t SinglyLinkedList::get_size() const
{
    return size;
}

bool SinglyLinkedList::is_empty() const
{
    return size == 0;
}

// Inputting a position greater than size-1 results in tail
Node* SinglyLinkedList::get_node(unsigned int position) const
{
    Node* current_node = head;
    for (unsigned int i = 0; i < position; i++)
    {
        if (current_node->next == NULL)
        {
            break;
        }
        current_node = current_node->next;
    }
    return current_node;
}

void SinglyLinkedList::print() const
{

}

