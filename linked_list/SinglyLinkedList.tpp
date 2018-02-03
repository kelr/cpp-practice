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
void SinglyLinkedList<T>::push_back(const T& input_data)
{
    Node<T>* new_node = {input_data, nullptr};
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
        Node<T>* curr_node = head;
        Node<T>* prev_node = head;
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
void SinglyLinkedList<T>::push_head(const T& input_data)
{
    Node<T>* new_node = {input_data, nullptr};
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
        Node<T>* temp_head = head;
        head = head->next;
        delete(temp_head);
        temp_head = nullptr;
        size--;   
    }
}

// Position starts from 0, which is head
template<class T>
void SinglyLinkedList<T>::insert(const T& input_data, SinglyLinkedList<T>::iterator position)
{
    Node<T>* new_node = {input_data, nullptr};
    new_node->data = input_data;

    Node<T>* curr_node = head;
    Node<T>* prev_node = head;
    iterator iter;

    for (iter = begin(); iter != position; iter++)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    prev_node->next = new_node;
    new_node->next = curr_node;

    prev_node = nullptr;
    curr_node = nullptr;
    size++;
}

template<class T>
void SinglyLinkedList<T>::remove(SinglyLinkedList<T>::iterator position)
{
    Node<T>* curr_node = head;
    Node<T>* prev_node = head;
    iterator iter;

    for (iter = begin(); iter != position; iter++)
    {
        prev_node = curr_node;
        curr_node = curr_node->next;
    }

    prev_node->next = curr_node->next;
    curr_node->next = nullptr;
    delete(curr_node);
    curr_node = nullptr;
    prev_node = nullptr;
    size--;
}

template<class T>
Node<T>* SinglyLinkedList<T>::get_head() const
{
    return head;
}

template<class T>
Node<T>* SinglyLinkedList<T>::get_tail() const
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
Node<T>* SinglyLinkedList<T>::get_node(iterator position) const
{
    Node<T>* current_node = head;
    iterator iter;
    for (iter = begin(); iter != position; iter++)
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
    Node<T>* current_node = head;
    int i = 0;
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

