// Leetcode 1. Two Sum

#include <vector>
#include <unordered_map>

class Solution 
{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) 
    {
        int complement = 0;
        std::vector<int> output;
        std::unordered_map<int, int> history;

        // Iterate through the input vector
        for (int i = 0; i < nums.size(); i++)
        {   
            // Find the complement for the current number
            complement = target - nums[i];

            // If we've seen this complement before, we're done
            if (history.count(complement) == 1)
            {
                output.push_back(history[complement]);
                output.push_back(i);
                break;
            }
            // If we didn't find a complement, save the current number and its index to be checked next iteration
            else
            {
                history[nums[i]] = i;
            }
        }
        return output;
    }
};