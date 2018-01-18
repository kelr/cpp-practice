#include <assert.h>

#include "vector.h"

int main(void)
{
    // Test default constructor
    KelVector<int> snacks;

    snacks.push_back(1);
    snacks.push_back(0);
    snacks.push_back(20);
    snacks.push_back(11);
    snacks.push_back(78);
    snacks.push_back(4654);
    snacks.push_back(131);
    snacks.push_back(1);
    snacks.print_all();

    //Test size init constructor
    KelVector<int> test_size_init(10);
    assert(test_size_init.capacity() == 10);
    assert(test_size_init.size() == 10);

    //Test populate constructor
    KelVector<int> test_populate(20, 5);
    test_populate.print_all();
    assert(test_populate.capacity() == 20);
    assert(test_populate.size() == 20);
    for (unsigned int i = 0; i < test_populate.size(); i++)
    {
        assert(test_populate[i] == 5);
    }

    // Test Copy Constructor 
    KelVector<int> test_copy_constructor(snacks);
    test_copy_constructor.print_all();


    KelVector<int> test_assignment_operator = snacks;;
    test_assignment_operator.print_all();

	return 0;
}