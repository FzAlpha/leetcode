#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Create an array to store the last index of each character.
        // Initialize with -1 to indicate character hasn't been seen yet.
        vector<int> char_map(256, -1);
        
        int left = 0;
        int max_len = 0;
        int n = s.length();
        
        for (int right = 0; right < n; right++) {
            // If the character was seen before AND is within the current window
            if (char_map[s[right]] != -1) {
                // Move the left pointer to the right of the previous occurrence
                // but ensure it never moves backward
                left = max(left, char_map[s[right]] + 1);
            }
            
            // Record the current character's index
            char_map[s[right]] = right;
            
            // Calculate the current window length and update the maximum
            max_len = max(max_len, right - left + 1);
        }
        
        return max_len;
    }
};
