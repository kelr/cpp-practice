template<class T>
QueueVector<T>::QueueVector()
{
    m_size = 0;
    m_capacity = 0;
    m_array = new T[0];
}

template<class T>
QueueVector<T>::~QueueVector()
{
    delete[] m_array;
}

template<class T>
void QueueVector<T>::enqueue(const T &element)
{
    // Uh oh the vector is full
    if (m_size == m_capacity)
    {
        // If there was actually stuff in the vector
        if (m_capacity != 0)
        {
            // Make a copy that's twice as big
            reserve(m_capacity * 2);
            // Add the new value
            m_array[m_size++] = element;
        }
        else
        {   
            // There was nothing in the vector so just make a new one with one space
            reserve(1);
            // Add the new value
            m_array[m_size] = element;
            m_size++;
        }
    }

}

template<class T>
T QueueVector<T>::dequeue()
{
    T ret_val = m_array[0];
    for (std::size_t i = 1; i < m_size; i++)
    {
        m_array[i-1] = m_array[i];
    }
    m_size--;

    return ret_val;
}

template<class T>
bool QueueVector<T>::is_empty() const
{
    return m_size == 0;
}

template<class T>
void QueueVector<T>::print() const
{
    for (std::size_t i = 0; i < m_size; i++)
    {
        std::cout << m_array[i];
        if (i != m_size-1)
        {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

template<class T>
void QueueVector<T>::reserve(std::size_t new_capacity)
{
    // Make a new array with a bigger capacity
    T* temp_array = new T[new_capacity];

    // Copy the values over
    for (std::size_t i = 0; i < m_size; i++)
    {
        temp_array[i] = m_array[i];
    }

    // Delete the old array if it wasn't empty
    if (m_array != NULL)
    {
        delete[] m_array;
    }

    // Set the new array as the member array and update the capacity
    m_array = temp_array;
    m_capacity = new_capacity;
}