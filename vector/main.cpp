#include <assert.h>
#include <iostream>
#include "vector.h"

int main(void)
{
    // Test default constructor
    KelVector<int> snacks;

    // Test emptyness 
    assert(snacks.is_empty());

    // Test push_back and dynamic reserving
    snacks.push_back(1);
    snacks.push_back(0);
    snacks.push_back(20);
    snacks.push_back(11);
    snacks.push_back(78);
    snacks.push_back(4654);
    snacks.push_back(131);
    snacks.push_back(15);

    // Test not empty 
    assert(!snacks.is_empty());

    //Test begin, end, front and back
    assert(snacks.begin()[0] == 1);
    assert(snacks.end()[0] == 15);
    assert(snacks.front() == 1);
    assert(snacks.back() == 15);

    // Test indexing operator
    assert(snacks[0] == 1);
    assert(snacks[1] == 0);
    assert(snacks[2] == 20);
    assert(snacks[3] == 11);
    assert(snacks[4] == 78);
    assert(snacks[5] == 4654);
    assert(snacks[6] == 131);
    assert(snacks[7] == 15);

    assert(snacks.capacity() == 8);
    assert(snacks.size() == 8);

    // Tests with a const vector
    const KelVector<int> const_snacks(snacks);

    // Test not empty 
    assert(!const_snacks.is_empty());

    //Test begin, end, front and back
    assert(const_snacks.begin()[0] == 1);
    assert(const_snacks.end()[0] == 15);
    assert(const_snacks.front() == 1);
    assert(const_snacks.back() == 15);

    // Test indexing operator
    assert(const_snacks[0] == 1);
    assert(const_snacks[1] == 0);
    assert(const_snacks[2] == 20);
    assert(const_snacks[3] == 11);
    assert(const_snacks[4] == 78);
    assert(const_snacks[5] == 4654);
    assert(const_snacks[6] == 131);
    assert(const_snacks[7] == 15);

    assert(const_snacks.capacity() == 8);
    assert(const_snacks.size() == 8);

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

    //Test pop_back
    snacks.pop_back();
    assert(snacks.capacity() == 7);
    assert(snacks.size() == 7);

    //Cleanup time
    snacks.clear();
    assert(snacks.is_empty());
    assert(snacks.capacity() == 0);
    assert(snacks.size() == 0);

    test_size_init.clear();
    assert(test_size_init.is_empty());
    assert(test_size_init.capacity() == 0);
    assert(test_size_init.size() == 0);

    test_populate.clear();
    assert(test_populate.is_empty());
    assert(test_populate.capacity() == 0);
    assert(test_populate.size() == 0);

    test_copy_constructor.clear();
    assert(test_copy_constructor.is_empty());
    assert(test_copy_constructor.capacity() == 0);
    assert(test_copy_constructor.size() == 0);

    test_assignment_operator.clear();
    assert(test_assignment_operator.is_empty());
    assert(test_assignment_operator.capacity() == 0);
    assert(test_assignment_operator.size() == 0);

	return 0;
}