// Last updated: 10/12/2026, 9:54:12 PM
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxC = 0;
        int c = 0;
        for(int i : nums){
            if(i == 1){
                c++;
                maxC = max(maxC,c);
            }else{
                c =0;
            }
        }
        return maxC;
    }
};