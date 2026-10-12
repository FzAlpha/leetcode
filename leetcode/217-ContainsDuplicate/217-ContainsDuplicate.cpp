// Last updated: 10/12/2026, 9:54:54 PM
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(auto n : nums){
            if(s.count(n) > 0){
                return true;
            }
            s.insert(n);
        }
        return false;
    }
};