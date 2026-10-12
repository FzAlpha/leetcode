// Last updated: 10/12/2026, 9:52:02 PM
class Solution {
    const int MOD = 1000000007;
public:
    int numberOfSets(int n, int k) {
        vector<int> dp(n), prefixsums(n+1);
        for(int j = 0;j<n;j++){
            dp[j]=1;
            prefixsums[j+1] = (prefixsums[j] + dp[j]) % MOD;
        }
        for(int i = 1; i<= k;i++){
            dp[0] = 0;
            for(int j =1; j < n ; j++){
                dp[j] = (dp[j-1] + prefixsums[j]) % MOD;
            }
            for(int j = 0; j < n ; j++){
                prefixsums[j+1] = (prefixsums[j] + dp[j]) % MOD;
            }
        }
        return dp[n-1];
    }
};