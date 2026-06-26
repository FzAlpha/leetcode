#include <vector>

class Solution {
public:
    long long countMajoritySubarrays(std::vector<int>& nums, int target) {
        int n = nums.size();
        
        // Offset shifts negative balances into positive indices. 
        // The lowest possible balance is -n, so adding n + 2 keeps everything > 0.
        int offset = n + 2; 
        
        // Fenwick Tree array to store the frequencies of prefix sums.
        // Needs size 2*n + 5 to safely cover balances from -n to +n plus the offset.
        std::vector<int> bit(2 * n + 5, 0);
        
        // Helper Lambda: Adds 'val' to the frequency at the given index
        auto add = [&](int index, int val) {
            for (; index < bit.size(); index += index & -index) {
                bit[index] += val;
            }
        };
        
        // Helper Lambda: Returns the sum of frequencies from 1 up to 'index'
        auto query = [&](int index) {
            int sum = 0;
            for (; index > 0; index -= index & -index) {
                sum += bit[index];
            }
            return sum;
        };
        
        long long totalSubarrays = 0;
        int runningBalance = 0;
        
        // Base case: A running balance of 0 has occurred exactly once at the start
        add(runningBalance + offset, 1);
        
        for (int i = 0; i < n; i++) {
            // Step 1: Update running balance (+1 for target, -1 for others)
            if (nums[i] == target) {
                runningBalance++;
            } else {
                runningBalance--;
            }
            
            // Step 2: Query the tree to find how many past balances are strictly smaller.
            // "Strictly smaller" means we check up to (runningBalance - 1).
            totalSubarrays += query(runningBalance - 1 + offset);
            
            // Step 3: Record the current running balance into the tree history
            add(runningBalance + offset, 1);
        }
        
        return totalSubarrays;
    }
};