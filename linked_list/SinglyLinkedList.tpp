#include "SinglyLinkedList.h"

template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

// Returns the pointer to the head of the vector
template<class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::begin()
{
    return head;
}

// Const version for the pointer to the head of the vector
template<class T>
const typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::begin() const
{
    return head;
}

// Returns the pointer to the butt of the vector
template<class T>
typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::end()
{
    return tail;
}

// Const version for the pointer to the butt of the vector
template<class T>
const typename SinglyLinkedList<T>::iterator SinglyLinkedList<T>::end() const
{
    return tail;
}

template<class T>
void SinglyLinkedList<T>::push_back(const &T input)
{
    Node<T> *new_node = new Node;
    new_node->data = input;

    // Set both head and tail to the new node if the list is empty
    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        new_node = nullptr;
    }
    // Add the node to the tail end
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    // Size will increase regardless of what we do
    size++;
}

template<class T>
void SinglyLinkedList<T>::pop_back()
{
    if (head == nullptr)
    {
        std::cout << "There's nothing in the list to pop" << std::endl;
    }
    else
    {
        Node* current_node = head;
        Node* previous_node = head;
        while (current_node->next != nullptr)
        {
            previous_node = current_node;
            current_node = current_node->next;
        }
        tail = previous_node;
        previous_node->next = nullptr;
        previous_node = nullptr;
        size--;
    }
}

template<class T>
void SinglyLinkedList<T>::push_head(const &T input)
{
    Node* new_node = new Node;
    new_node->data = input;

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
        new_node = nullptr;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    size++;
}

template<class T>
void SinglyLinkedList<T>::pop_head()
{
    if (head == nullptr)
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
template<class T>
void SinglyLinkedList<T>::insert(const &T data, SinglyLinkedList<T>::iterator position)
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
    previous_node = nullptr;
    current_node = nullptr;
    size++;
}

template<class T>
void SinglyLinkedList<T>::remove(unsigned int position)
{
    Node* current_node = head;
    Node* previous_node = head;
    for (unsigned int i = 0; i < position; i++)
    {
        previous_node = current_node;
        current_node = current_node->next;
    }
    previous_node->next = current_node->next;
    current_node->next = nullptr;
    current_node = nullptr;
    previous_node = nullptr;
    size--;
}

template<class T>
Node* SinglyLinkedList<T>::get_head() const
{
    return head;
}

template<class T>
Node* SinglyLinkedList<T>::get_tail() const
{
    return tail;
}

template<class T>
std::size_t SinglyLinkedList<T>::get_size() const
{
    return size;
}

template<class T>
bool SinglyLinkedList<T>::is_empty() const
{
    return size == 0;
}

// Inputting a position greater than size-1 results in tail
template<class T>
Node* SinglyLinkedList<T>::get_node(iterator position) const
{
    Node* current_node = head;
    for (unsigned int i = 0; i < position; i++)
    {
        if (current_node->next == nullptr)
        {
            break;
        }
        current_node = current_node->next;
    }
    return current_node;
}

template<class T>
void SinglyLinkedList<T>::print() const
{
    Node* current_node = head;
    unsigned int i = 0;
    std::cout << "============== SinglyLinkedList size " << size << " ==================" << std::endl; 
    while (1)
    {
        std::cout << "[Node Position: " << i << " Data: " << current_node->data << "]";
        if (i == 0)
        {
            std::cout << " <---- HEAD"; 
        }
        if (current_node->next == nullptr)
        {
            std::cout << " <---- TAIL" << std::endl; 
            std::cout << "                |\n";
            std::cout << "                |\n";
            std::cout << "                V\n";
            std::cout << "               NULL\n\n";
            break;
        }
        else
        {
            std::cout << std::endl;
            std::cout << "                |\n";
            std::cout << "                |\n";
            std::cout << "                V\n";
        }
        current_node = current_node->next;
        i++;
    }
    current_node = nullptr;
}

