class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> seen(nums.begin(), nums.end());
        vector <int> ans;

        int minValue = *min_element(nums.begin(), nums.end());
        int maxValue = *max_element(nums.begin(), nums.end());

        for (int i = minValue; i <= maxValue; i++) {
            if (seen.find(i) == seen.end()) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};