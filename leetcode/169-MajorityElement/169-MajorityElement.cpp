// Last updated: 10/12/2026, 9:55:17 PM
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int freq = 0, ans = 0;
        for (int i = 0;i<nums.size();i++){
            if(freq ==0){
                ans = nums[i];
            }
            if(ans == nums[i]){
                freq++;
            }
            else{
                freq--;
            }
        }
        return ans;
    }
};