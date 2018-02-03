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
    //TODO: delete all the nodes that we new'ed
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
void SinglyLinkedList<T>::push_back(const T &input_data)
{
    Node* new_node = new Node;
    new_node->data = input_data;

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }
    new_node = nullptr;
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
        // Gotta come in from the front...which is O(n)...lame
        Node* curr_node = head;
        Node* prev_node = head;
        while (curr_node->next != nullptr)
        {
            prev_node = curr_node;
            curr_node = curr_node->next;
        }
        tail = prev_node;
        prev_node->next = nullptr;
        prev_node = nullptr;
        size--;
    }
}

template<class T>
void SinglyLinkedList<T>::push_head(const T &input_data)
{
    Node* new_node = new Node;
    new_node->data = input_data;

    if (head == nullptr)
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        new_node->next = head;
        head = new_node;
    }
    new_node = nullptr;
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
        Node* temp_head = head;
        head = head->next;
        delete(temp_head);
        temp_head = nullptr;
        size--;   
    }
}

// Position starts from 0, which is head
template<class T>
void SinglyLinkedList<T>::insert(const T &input_data, int position)
{
    // Make sure the input is legit
    assert(position <= size-1);
    // Edge case
    if (position == 0)
    {
        push_head(input_data);
    }
    else
    {
        Node* new_node = new Node;
        new_node->data = input_data;

        Node* curr_node = head;
        Node* prev_node = head;

        if (curr_node != nullptr)
        {
            for (std::size_t i = 0; i != position; i++)
            {
                curr_node = curr_node->next;
            }
            prev_node->next = new_node;
            new_node->next = curr_node;

            prev_node = nullptr;
            curr_node = nullptr;
            size++;
        }
    }
}

template<class T>
void SinglyLinkedList<T>::remove(int position)
{
    if (position == 0)
    {
        pop_head();
    }
    else if (position == size-1)
    {
        pop_back();
    }
    else
    {
        Node* curr_node = head;
        Node* prev_node = head;
        if (curr_node != nullptr)
        {
            for (std::size_t i = 0; i != position; i++)
            {
                curr_node = curr_node->next;
            }
            prev_node->next = curr_node->next;
            curr_node->next = nullptr;
            delete(curr_node);
            curr_node = nullptr;
            prev_node = nullptr;
            size--;
        }
    }
}

template<class T>
T SinglyLinkedList<T>::get_head() const
{
    return head->data;
}

template<class T>
T SinglyLinkedList<T>::get_tail() const
{
    return tail->data;
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

template<class T>
void SinglyLinkedList<T>::print() const
{
    Node* curr_node = head;
    int i = 0;
    std::cout << "============== SinglyLinkedList size " << size << " ==================" << std::endl; 
    if (curr_node != nullptr)
    {
        for (std::size_t i = 0; i < size; i++)
        {
            std::cout << "[Node Position: " << i << " Data: " << curr_node->data << "]";
            if (i == 0)
            {
                std::cout << " <---- HEAD"; 
            }
            if (curr_node->next == nullptr)
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
            curr_node = curr_node->next;
        }
        curr_node = nullptr;
}}

template<class T>
T SinglyLinkedList<T>::get_data_at(int position) const
{
    return get_node(position)->data;
}

template<class T>
void SinglyLinkedList<T>::reverse()
{

}

template<class T>
void SinglyLinkedList<T>::remove_first_encounter(const T &input_data)
{
    // If C++ had decorators that would be nice
    if (head != nullptr)
    {
        if (head->data == input_data)
        {
            pop_head();
        }
        else
        {
            Node* curr_node = head;
            Node* prev_node = head;
            iterator iter;

            while (curr_node->next != nullptr)
            {
                if (curr_node->data == input_data)
                {
                    prev_node->next = curr_node->next;
                    curr_node->next = nullptr;
                    delete(curr_node);
                    curr_node = nullptr;
                    prev_node = nullptr;
                    size--;
                }
                else
                {
                    prev_node = curr_node;
                    curr_node = curr_node->next;
                }
            }
        }
    }
}


// Inputting a position greater than size-1 results in tail
template<class T>
typename SinglyLinkedList<T>::Node* SinglyLinkedList<T>::get_node(int position) const
{
    // Make sure the input is legit
    assert(position <= size);

    Node* curr_node = head;
    if (curr_node != nullptr)
    {
        for (std::size_t i = 0; i != position; i++)
        {
            curr_node = curr_node->next;
        }
    }
    return curr_node;
}