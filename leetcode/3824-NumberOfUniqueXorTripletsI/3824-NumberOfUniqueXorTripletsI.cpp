// Last updated: 10/12/2026, 9:49:52 PM
class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if(n<3) return n;

        return 1<<bit_width((unsigned)n);
    }
};