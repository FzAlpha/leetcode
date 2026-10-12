// Last updated: 10/12/2026, 9:51:16 PM
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        ans.reserve(nums.size());
        for(int i : nums){
            if( i< pivot){
                ans.push_back(i);
            }
        }
        for(int i : nums){
            if( i == pivot){
                ans.push_back(i);
            }
        }
        for(int i : nums){
            if( i > pivot){
                ans.push_back(i);
            }
        }
        return ans;
        
    }
};