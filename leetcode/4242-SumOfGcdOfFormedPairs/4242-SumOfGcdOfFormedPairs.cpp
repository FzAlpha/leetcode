// Last updated: 10/12/2026, 9:49:00 PM
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int maxV =0;
        for(int i= 0; i< n ; i++){
            maxV = max(maxV, nums[i]);
            nums[i] = __gcd(nums[i],maxV);
        }

        sort(nums.begin(), nums.end());

        long long res = 0;
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            res += __gcd(nums[i], nums[j]);
        }

        return res;
    }
};