#include <math.h>
#include <sstream>
#include <iostream>

class Solution 
{
public:
    int reverse(int x) 
    {
        bool is_neg = false;
        if (x < 0)
        {
            x = -x;
            is_neg = true;
            std::cout << x;
        }
        int size = get_digits(x);
        
        int output_array[size] = {};
        int tmp;
        int j = 0;
        // Stuff the int into an array
        for (int i = size-1; i >= 0; i--) 
        {
            tmp = x % 10;
            x /= 10;
            output_array[j] = tmp;
            if (size==10)
            {
                std::cout << "hi";
                if (output_array[0] > 2)
                {
                    return 0;
                }
            }
            j++;
        }

        std::stringstream stream;

        for (int k = 0; k < size; k++)
            stream << output_array[k];

        int result;
        stream >> result;

        
        if (is_neg)
        {
            result = result * -1;
        }
        
        return result;
    }
    int get_digits(int i)
    {
        return i > 0 ? (int) log10 ((double) i) + 1 : 1;
    }
};