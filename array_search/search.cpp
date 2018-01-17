#include <search.h>

int sequential_search(int target, const int target_array[])
{   
    //Oh boy I sure hope there's things in the array
    int ret_val = -1;
    std::size_t size = sizeof(target_array) / sizeof(target_array[0]);
    for (std::size_t i = 0; i < size, i++)
    {
        if (target == target_array[i])
        {
            ret_val = i;
        }
    }
    return ret_val;
}


int binary_search(int target, const int sorted_array[])
{
    //Oh boy I sure hope this array is sorted
    std::size_t size = sizeof(sorted_array) / sizeof(sorted_array[0]);
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
        }
        else
        {
            high = mid - 1
            mid = static_cast<std::size_t>(floor((static_cast<float>(high) + static_cast<float>(low)) / 2.0));
        }
    }
    return found_target;
}
