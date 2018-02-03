template<class T>
QueueLinkedList<T>::QueueLinkedList()
{
    head = nullptr;
    tail = nullptr;
}

template<class T>
QueueLinkedList<T>::~QueueLinkedList()
{
    Node* tmp_node = head;
    while (head->next != nullptr)
    {
        tmp_node = head;
        head = head->next;
        delete(tmp_node);
    }
    // Edge delete, could delete tail too
    delete(head);
    tmp_node = nullptr;
    head = nullptr;
    tail = nullptr;
}

template<class T>
void QueueLinkedList<T>::enqueue(const T &data)
{
    // Don't enqueue at the head otherwise dequeue will be O(n)
    Node* new_node = new Node;
    new_node->data = data;
    if (is_empty())
    {
        head = new_node;
        tail = new_node;
    }
    else
    {
        tail->next = new_node;
        tail = new_node;
    }

}

template<class T>
void QueueLinkedList<T>::dequeue()
{
    if (is_empty())
    {
        std::cout << "Nothing in the queue" << std::endl;
    }
    else
    {
        Node* tmp_node = head;
        head = head->next;
        delete(tmp_node);
        tmp_node = nullptr;
    }
}

template<class T>
bool QueueLinkedList<T>::is_empty()
{
    return head == nullptr;
}

template<class T>
void QueueLinkedList<T>::print()
{

}