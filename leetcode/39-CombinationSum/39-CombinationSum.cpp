// Last updated: 10/12/2026, 9:56:42 PM
class Solution {
public:
    void backtrack(int index, int target, vector<int>& candidates, 
                   vector<vector<int>>& ans, vector<int>& current) {
        
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        
        
        if (index == candidates.size() || target < 0) {
            return;
        }

        
        current.push_back(candidates[index]);
        backtrack(index, target - candidates[index], candidates, ans, current);
        
        
        current.pop_back();

        
        backtrack(index + 1, target, candidates, ans, current);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> current;
        backtrack(0, target, candidates, ans, current);
        return ans;
    }
};
