#include <assert.h>

#include <search.h>

int main()
{
    const int test_array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    int target = 3;
    int seq_result = sequential_search(target, test_array);
    int binary_result = binary_search(target, test_array);
    assert(seq_result == 3)
    assert(binary_result == 3)
	return 0;
}