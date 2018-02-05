// Leetcode 3. Longest Substring Without Repeating Characters

#include <unordered_map>
#include <string>

// I got a 10.72 FeelsBadMan
class Solution 
{
public:
    std::size_t current_index;
    std::size_t last_start_index;
    int lengthOfLongestSubstring(string s) 
    {
        if (s.length() == 0)
        {
            return 0;
        }
        if (s.length() == 1)
        {
            return 1;
        }
        int count = 0;
        int current_max = 0;
        current_index = 0;
        last_start_index = 0;
        std::unordered_map<char, std::size_t> history;
        while (current_index < s.length()-1)
        {
            for (std::size_t j = last_start_index; j < s.length(); j++)
            {
                // Char seen before
                if (history.count(s[j]) == 1)
                {
                    // Restart at the first time we saw this char
                    last_start_index = history[s[j]] + 1;
                    current_index = j;
                    count = 0;
                    history.clear();
                    break;
                }
                else
                {
                    count++;
                    if (count > current_max)
                    {
                        current_max = count;
                    }
                    history[s[j]] = j;
                }
            }
        }
        return current_max;
    }
};