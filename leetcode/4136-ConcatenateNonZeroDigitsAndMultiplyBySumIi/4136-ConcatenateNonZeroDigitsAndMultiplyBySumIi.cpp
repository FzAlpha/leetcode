// Last updated: 10/12/2026, 9:49:04 PM
class Solution {
public:
    int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n = s.length();

        vector<long long> sumD(n + 1, 0);
        vector<long long> cntN0(n + 1, 0);
        vector<long long> p(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for (int i = 1; i <= n; i++) {
            power10[i] = (power10[i - 1] * 10) % MOD;
        }

        for (int i = 0; i < n; i++) {
            int digit = s[i] - '0';

            sumD[i + 1] = sumD[i] + digit;
            cntN0[i + 1] = cntN0[i];
            p[i + 1] = p[i];

            if (digit != 0) {
                cntN0[i + 1]++;
                p[i + 1] = (p[i] * 10 + digit) % MOD;
            }
        }

        vector<int> ans;
        for (auto& query : q) {
            int l = query[0];
            int r = query[1];

            long long sd = sumD[r + 1] - sumD[l];
            long long n0 = cntN0[r + 1] - cntN0[l];

            ans.push_back((((p[r + 1] - (p[l] * power10[n0]) % MOD + MOD) % MOD) * (sd % MOD)) % MOD);
        }

        return ans;
    }
};