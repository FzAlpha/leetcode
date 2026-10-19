// Last updated: 10/19/2026, 4:49:21 PM
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int left = ranges::count_if(nums, [&](int x) { return x < target; }); 
        int right = ranges::count_if(nums, [&](int x) { return x <= target; });
        vector<int> indices(right - left);
        iota(indices.begin(), indices.end(), left);
        return indices;
    }
};