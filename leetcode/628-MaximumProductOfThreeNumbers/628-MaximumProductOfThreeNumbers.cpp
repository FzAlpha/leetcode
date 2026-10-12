// Last updated: 10/12/2026, 9:53:49 PM
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        nth_element(nums.begin() , nums.begin()+1 , nums.end());
        int min1 = nums[0];
        int min2 = nums[1];

        nth_element(nums.begin() , nums.begin() + 2 , nums.end() , greater<int>());
        int max1 = nums[0];
        int max2 = nums[1];
        int max3 = nums[2];

        int abs_max = max({max1 , max2 , max3});

        return max(max1 * max2 * max3, min1 * min2 * abs_max);
    }
};