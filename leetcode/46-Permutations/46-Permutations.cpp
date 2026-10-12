// Last updated: 10/12/2026, 9:56:38 PM
class Solution {
public:

    void getpermutation(vector<int>& nums , int indx , vector<vector<int>>& ans){

        if(indx == nums.size()){
            ans.push_back(nums);
            return;
        }

        for(int i = indx ; i<nums.size() ; i++){
            swap(nums[indx] , nums[i]);
            getpermutation(nums , indx + 1 , ans);

            swap(nums[indx] , nums[i]);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        getpermutation(nums , 0 , ans);
        return ans;
    }
};