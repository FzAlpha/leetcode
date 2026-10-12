// Last updated: 10/12/2026, 9:49:26 PM
class Solution {
    const int mod=1000000007;
    #define ll long long
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        for(auto &t:queries){
            int l=t[0];
            int r=t[1];
            int k=t[2];
            int v=t[3];
            int idx=l;
            while(idx<=r){
                ll temp=nums[idx];
                nums[idx]=(temp*v)%mod;
                idx+=k;
            }
        }
        int ans=0;
        for(int num:nums){
            ans^=num;
        }
        return ans;
    }
};