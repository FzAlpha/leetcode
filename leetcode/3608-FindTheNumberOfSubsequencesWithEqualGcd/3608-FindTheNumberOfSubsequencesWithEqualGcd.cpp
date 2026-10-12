// Last updated: 10/12/2026, 9:50:15 PM
class Solution {
public:
    int t[201][201][201];
    int MOD = 1e9+7;

    int solve(vector<int>& nums, int i, int first, int sec) {

        if (i == nums.size()) {
            bool bothNonEmpty = (first != 0 && sec != 0);
            bool gcdMatch = (first == sec);
            return (bothNonEmpty && gcdMatch) ? 1 : 0;
        }

        if(t[i][first][sec] != -1){
            return t[i][first][sec];
        }

        int skip = solve(nums, i + 1, first, sec);
        int take1 = solve(nums, i + 1, __gcd(first, nums[i]), sec);
        int take2 = solve(nums, i + 1, first, __gcd(sec, nums[i]));

        return t[i][first][sec] = (0LL + skip + take1 + take2) % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        memset(t , -1 , sizeof(t));
        return solve(nums, 0, 0, 0); 
    }
};