// Letcode 4. Median of two sorted arrays

#include <math.h>
#include <vector>
#include <cstddef>
#include <iostream>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) 
    {
        std::size_t size_1 = nums1.size();
        std::size_t size_2 = nums2.size();
        float median_1 = 0;
        float median_2 = 0;
        float median_index_1 = (((float)size_1 + 1)/2) - 1;
        float median_index_2 = (((float)size_2 + 1)/2) - 1;

        if (size_1 == 0)
        {
            median_1 = 0;
        }
        else if (size_1 % 2 == 0)
        {
            median_1 = ((float)nums1[floor(median_index_1)] + (float)nums1[ceil(median_index_1)]) / 2;
        }
        else
        {
            median_1 = nums1[median_index_1];
        }
        
        if (size_2 == 0)
        {
            median_2 = 0;
        }
        else if (size_2 % 2 == 0)
        {
            median_2 = ((float)nums2[floor(median_index_2)] + (float)nums2[ceil(median_index_2)]) / 2;
        }
        else
        {
            median_2 = nums2[median_index_2];
        }
        double test = 0;
        
        if (size_1 == 0)
        {
            test = (median_2) / 2;
        }
        else if (size_2 == 0)
        {
            test = (median_1) / 2;
        }
        else
        {
            test = (median_1 + median_2) / 2;
        }
    
        return test;
    }

};

int main()
{
    Solution sol = Solution();

    std::vector<int>vec1 = {2};
    std::vector<int>vec2 = {1,3};
    std::cout << sol.findMedianSortedArrays(vec1, vec2);

    return 0;
}