// Last updated: 10/12/2026, 9:48:56 PM
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxSoFar = -1;
        int cand = 0, cMax = 0;

        for (int i = 0; i < nums.size(); i++) {
            maxSoFar = max(maxSoFar, nums[i]);

            if (i == cand) cMax = maxSoFar;

            if (nums[i] < cMax - k)
                cand = i + 1;
        }

        return cand < nums.size() ? cand : -1;
    }
};