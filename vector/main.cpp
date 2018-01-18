#include <assert.h>

#include "vector.h"

int main(void)
{
    // Test default constructor
    KelVector<int> snacks;

    // Test emptyness 
    assert(snacks.empty());

    // Test push_back and dynamic resizing
    snacks.push_back(1);
    snacks.push_back(0);
    snacks.push_back(20);
    snacks.push_back(11);
    snacks.push_back(78);
    snacks.push_back(4654);
    snacks.push_back(131);
    snacks.push_back(1);

    // Test not empty 
    assert(!snacks.empty());

    // Test indexing operator
    assert(snacks[0] == 1);
    assert(snacks[1] == 0);
    assert(snacks[2] == 20);
    assert(snacks[3] == 11);
    assert(snacks[4] == 78);
    assert(snacks[5] == 4654);
    assert(snacks[6] == 131);
    assert(snacks[7] == 1);

    //Test size init constructor
    KelVector<int> test_size_init(10);
    assert(test_size_init.capacity() == 10);
    assert(test_size_init.size() == 10);

    //Test populate constructor
    KelVector<int> test_populate(20, 5);
    assert(test_populate.capacity() == 20);
    assert(test_populate.size() == 20);
    for (unsigned int i = 0; i < test_populate.size(); i++)
    {
        assert(test_populate[i] == 5);
    }

    // Test Copy Constructor 
    KelVector<int> test_copy_constructor(snacks);
    for (unsigned int i = 0; i < test_copy_constructor.size(); i++)
    {
        assert(test_copy_constructor[i] == snacks[i]);
    }

    // Test assignment operator
    KelVector<int> test_assignment_operator = snacks;
    for (unsigned int i = 0; i < test_assignment_operator.size(); i++)
    {
        assert(test_assignment_operator[i] == snacks[i]);
    }


	return 0;
}