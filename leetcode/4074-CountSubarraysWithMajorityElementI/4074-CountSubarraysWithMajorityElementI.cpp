// Last updated: 10/12/2026, 9:49:17 PM
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int t) {
        int n = nums.size();
        unordered_map<int, int> m;
        m[0] = 1;
        int running = 0;
        int curr = 0;
        int small = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == t) {
                small += m[running];
                running++;
            } else {
                running--;
                small -= m[running];
            }
            curr += small;
            m[running]++;
        }
        return curr;
    }
};