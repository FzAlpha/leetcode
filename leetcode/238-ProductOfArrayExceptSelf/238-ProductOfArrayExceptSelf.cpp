// Last updated: 10/12/2026, 9:54:40 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        auto init = []() {
     ios::sync_with_stdio(false);
     cin.tie(nullptr);
     cout.tie(nullptr);
     return 'c';
      }();
        int n = nums.size();
        
        vector<int> ans(n,1);
        int suffix = 1;
        
        //prefix
        for(int i=1;i<n;i++){
            ans[i]= ans[i-1]*nums[i-1];
        }
        //sufix
        for(int i =n-2;i>=0;i--){
            suffix *=nums[i+1];
            ans[i] *= suffix;
        }
       
        
        return ans;
    }
};