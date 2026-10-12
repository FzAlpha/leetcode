// Last updated: 10/12/2026, 9:49:49 PM
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& q) {
        vector<int> comp(n,0);
        vector<bool> ans;

        for(int i = 1 ; i< n ; i++){
            if(nums[i] - nums[i-1] <= maxDiff){
                comp[i] = comp[i-1];
            }else{
                comp[i] = comp[i-1]+1;
            }
        }

        for(auto i : q){
            ans.push_back(comp[i[0]] == comp[i[1]]);
        }
        
        return ans;
    }
};