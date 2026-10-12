// Last updated: 10/12/2026, 9:53:48 PM
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> freq(n+1);
        vector<int> res(2);
        for(int i = 0; i<nums.size() ;i++){
            int val = nums[i];
            freq[val]++;
        }

        for(int i =1 ; i<=n;i++){
            if(freq[i] == 2){
                res[0] = i;
            }else if(freq[i] == 0){
                res[1] = i;
            }
        }
        return res;
    }
};