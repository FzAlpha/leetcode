// Last updated: 10/12/2026, 9:56:06 PM
#include <vector>
using namespace std;

class Solution {
public:
    
    void allsubset(vector<int>& nums, vector<int>& current, int i, vector<vector<int>>& sets) {
        if (i == nums.size()) {
            sets.push_back(current); 
            return;
        }

       
        current.push_back(nums[i]);
        allsubset(nums, current, i + 1, sets);

        
        current.pop_back();
        allsubset(nums, current, i + 1, sets);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> sets;
        vector<int> current;
        allsubset(nums, current, 0, sets);
        return sets;
    }
};
