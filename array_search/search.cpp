#include <cassert> //assert
#include <cmath> //floor
#include <search.h>

int sequential_search(int target, const int *target_array, std::size_t size)
{   
    //Oh boy I sure hope there's things in the array
    int ret_val = -1;
    for (std::size_t i = 0; i < size; i++)
    {
        if (target == target_array[i])
        {
            ret_val = i;
        }
    }
    return ret_val;
}

int binary_search(int target, const int *sorted_array, std::size_t size)
{
    //Oh boy I sure hope this array is sorted
    int low_index = 0;
    int mid_index = 0;
    // I have to use int otherwise the alg won't terminate when you try to find a value < arr[0]
    int high_index = static_cast<int>(size) - 1;
    int found_target = -1;

    while ((low_index <= high_index) && (found_target == -1))
    {
        //Arent types just great? 
        mid_index = static_cast<int>(floor((static_cast<float>(high_index) + static_cast<float>(low_index)) / 2.0));
        if (target == sorted_array[mid_index])
        {
            found_target = mid_index;
        }
        else if (target < sorted_array[mid_index])
        {
            high_index = mid_index - 1;
        }
        else
        {
            low_index = mid_index + 1;
        }
    }
    return found_target;
}

int main(void)
{
    const int test_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    const int bigger_array[25] = {0, 5, 7, 20, 23, 263, 277, 289, 310, 321, 353, 363, 389, 410, 420, 430, 440, 500, 600, 700, 999, 1024, 2048, 2500, 9999};
    // Get the size of the C style array
    std::size_t size = sizeof(test_array)/sizeof(test_array[0]);
    std::size_t size_bigger = sizeof(bigger_array)/sizeof(bigger_array[0]);

    assert(sequential_search(3, test_array, size) == 2);
    assert(sequential_search(4, test_array, size) == 3);
    assert(sequential_search(0, test_array, size) == -1);
    assert(sequential_search(10, test_array, size) == 9);

    assert(sequential_search(263, bigger_array, size_bigger) == 5);
    assert(sequential_search(2500, bigger_array, size_bigger) == 23);
    assert(sequential_search(777, bigger_array, size_bigger) == -1);
    assert(sequential_search(0, bigger_array, size_bigger) == 0);

    assert(binary_search(3, test_array, size) == 2);
    assert(binary_search(4, test_array, size) == 3);
    assert(binary_search(0, test_array, size) == -1);
    assert(binary_search(10, test_array, size) == 9);    

    assert(binary_search(263, bigger_array, size_bigger) == 5);
    assert(binary_search(2500, bigger_array, size_bigger) == 23);
    assert(binary_search(777, bigger_array, size_bigger) == -1);
    assert(binary_search(0, bigger_array, size_bigger) == 0);

    return 0;
}