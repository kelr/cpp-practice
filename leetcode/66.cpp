// Leetcode Problem 66. Plus One

// 3-4ms, the percentile is weird though. I spent way too long trying to optimize this.
// Best case O(1) (Last index is < 9)
// Worst case O(n+2) (The entire array is 9 and we have to make the vector bigger)
class Solution 
{
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        int size = digits.size();
        for (int i = size-1; i >= 0; i--)
        {
            if (digits[i]++ < 9)
            {
                return digits;
            }
            digits[i] = 0;
        }
        digits[0] = 1;
        digits.push_back(0);
        return digits;
    }
};