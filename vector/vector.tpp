// Default constructor
template<class T>
KelVector<T>::KelVector()
    : m_array(0)
    , m_size(0)
    , m_capacity(0)
{
}

// Constructor that initializes an empty vector to a certain size
template<class T>
KelVector<T>::KelVector(std::size_t size)
{
    m_array = new T[size];
    m_size = size;
    m_capacity = size;
}

// Constructor that populates a vector of a certain size with an initial value
template<class T>
KelVector<T>::KelVector(std::size_t size, const T& initial)
{
    m_array = new T[size];
    m_size = size;
    m_capacity = size;

    // Populate the vector with initial values
    for(int i = 0; i < size; i++)
    {
        m_array[i] = initial;
    }
}

// Copy constructor
template<class T>
KelVector<T>::KelVector(const KelVector<T> & other_vector)
{
    // Copy the attributes of the other vector
    m_array = new T[other_vector.m_capacity];
    m_size = other_vector.m_size;
    m_capacity = other_vector.m_capacity;

    //Copy over the elements
    for(int i = 0; i < m_size; i++)
    {
        m_array[i] = other_vector.m_array[i];
    }
}

// Destructor
template<class T>
KelVector<T>::~KelVector()
{
    delete[] m_array;
}

// Indexing operator
template<class T>
T& KelVector<T>::operator[](std::size_t index)
{
    // Some dynamic range checking
    assert((index >= 0) && (index < m_size));
    return m_array[index];
}

// Const indexing operator
template<class T>
const T& KelVector<T>::operator[](std::size_t index) const
{
    // Some dynamic range checking
    assert((index >= 0) && (index < m_size));
    return m_array[index];
}

// Assignment operator
template<class T>
KelVector<T>& KelVector<T>::operator=(const KelVector<T> & other_vector)
{
    // Delete the old array and make a new one
    delete[] m_array;
    m_array = new T[other_vector.m_capacity];

    // Copy the size and capacity
    m_size = other_vector.m_size;
    m_capacity = other_vector.m_capacity;

    // Copy over the elements
    for(std::size_t i = 0; i < m_size; i++)
    {
        m_array[i] = other_vector.m_array[i];
    }
    return *this;
}

template<class T>
void KelVector<T>::reserve(std::size_t new_capacity)
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

// Checks if the vector is empty
template<class T>
bool KelVector<T>::is_empty() const
{
    return m_size == 0;
}

// Returns the pointer to the head of the vector
template<class T>
typename KelVector<T>::Iterator KelVector<T>::begin()
{
    return m_array;
}

// Const version for the pointer to the head of the vector
template<class T>
const typename KelVector<T>::Iterator KelVector<T>::begin() const
{
    return m_array;
}

// Returns the pointer to the butt of the vector
template<class T>
typename KelVector<T>::Iterator KelVector<T>::end()
{
    return m_array + (size() - 1);
}

// Const version for the pointer to the butt of the vector
template<class T>
const typename KelVector<T>::Iterator KelVector<T>::end() const
{
    return m_array + (size() - 1);
}

// Get the first value in the vector. Same as using KelVector[0]
template<class T>
T& KelVector<T>::front()
{
    return m_array[0];
}

// Const version to get the first value in the vector.
template<class T>
const T& KelVector<T>::front() const
{
    return m_array[0];
}

// Get the last value in the vector. Same as using KelVector[KelVector.size() - 1]
template<class T>
T& KelVector<T>::back()
{
    return m_array[m_size - 1];
}

// Const version to get the last value in the vector.
template<class T>
const T& KelVector<T>::back() const
{
    return m_array[m_size - 1];
}

// Return the total space the vector takes up (including empty space)
template<class T>
const std::size_t KelVector<T>::capacity() const
{
    return m_capacity;
}

// Return the number of elements in the vector
template<class T>
const std::size_t KelVector<T>::size() const
{
    return m_size;
}

// Add a value to the butt of the vector. Resizes the vector if we have reached capacity.
template<class T>
void KelVector<T>::push_back(const T& element)
{
    // Uh oh the vector is full
    if (m_size == m_capacity)
    {
        // If there was actually stuff in the vector
        if (m_capacity != 0)
        {
            // Make a copy that's twice as big
            reserve(m_capacity * 2);
        }
        else
        {   
            // There was nothing in the vector so just make a new one with one space
            reserve(1);
        }
    }
    // Add the new value
    m_array[m_size++] = element;
}

// Removes the value at the butt of the vector
template<class T>
void KelVector<T>::pop_back()
{
    m_size--;
    m_capacity--;
}

// Blows up the vector
template<class T>
void KelVector<T>::clear()
{
    delete[] m_array;
    T* m_array;
    m_size = 0;
    m_capacity = 0;

}

// Prints all elements in the vector
template<class T>
void KelVector<T>::print_all()
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