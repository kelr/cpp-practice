#include <cassert>
#include <cmath> //floor
#include <iostream>
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
    std::size_t low = 0;
    std::size_t mid = 0;
    std::size_t high = size;
    int found_target = -1;

    //Arent types just great? 
    mid = static_cast<std::size_t>(floor((static_cast<float>(high) + static_cast<float>(low)) / 2.0));

    while (low != high && found_target == -1)
    {
        if (target == sorted_array[mid])
        {
            found_target = mid;
        }
        else if (target > sorted_array[mid])
        {
            low = mid + 1;
            mid = static_cast<std::size_t>(floor((static_cast<float>(high) + static_cast<float>(low)) / 2.0));
            std::cout << mid << std::endl;
        }
        else
        {
            high = mid - 1;
            mid = static_cast<std::size_t>(floor((static_cast<float>(high) + static_cast<float>(low)) / 2.0));
        }
    }
    return found_target;
}

int main(void)
{
    const int test_array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // Get the size of the C style array
    std::size_t size = sizeof(test_array)/sizeof(test_array[0]);

    int target = 3;

    int seq_result = sequential_search(target, test_array, size);
    int binary_result = binary_search(target, test_array, size);
    //std::cout << seq_result << std::endl;
    //std::cout << binary_result << std::endl;
    assert(seq_result == 2);
    assert(binary_result == 2);

    seq_result = sequential_search(8, test_array, size);
    binary_result = binary_search(8, test_array, size);
    //std::cout << seq_result << std::endl;
    //std::cout << binary_result << std::endl;
    assert(seq_result == 7);
    assert(binary_result == 7);
    return 0;
}