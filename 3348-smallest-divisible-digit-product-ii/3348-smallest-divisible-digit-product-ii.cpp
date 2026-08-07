class Solution {
private:
    const int DIGIT_FACTORS[10][4] = {
        {0, 0, 0, 0}, // 0
        {0, 0, 0, 0}, // 1
        {1, 0, 0, 0}, // 2
        {0, 1, 0, 0}, // 3
        {2, 0, 0, 0}, // 4
        {0, 0, 1, 0}, // 5
        {1, 1, 0, 0}, // 6
        {0, 0, 0, 1}, // 7
        {3, 0, 0, 0}, // 8
        {0, 2, 0, 0}  // 9
    };

    vector<int> getPrimes(long long t) {
        vector<int> cnt(4, 0);
        int primes[4] = {2, 3, 5, 7};
        for (int i = 0; i < 4; i++) {
            while (t % primes[i] == 0) {
                cnt[i]++;
                t /= primes[i];
            }
        }
        if (t > 1) return {-1}; // Impossible: t has prime factors > 7
        return cnt;
    }

    int minDigits(const vector<int>& req) {
        int c2 = max(0, req[0]);
        int c3 = max(0, req[1]);
        int c5 = max(0, req[2]);
        int c7 = max(0, req[3]);
        
        int res = c7 + c5 + (c2 / 3) + (c3 / 2);
        int r2 = c2 % 3, r3 = c3 % 2;
        
        if (r2 == 2 && r3 == 1) res += 2;
        else if (r2 > 0 || r3 > 0) res += 1;
        
        return res;
    }

    vector<int> subtractDigit(vector<int> req, int d) {
        for (int j = 0; j < 4; j++) {
            req[j] = max(0, req[j] - DIGIT_FACTORS[d][j]);
        }
        return req;
    }

    // O(1) string construction: fill extra leading space with '1's instantly
    string buildSmallest(int len, vector<int> req) {
        int m = minDigits(req);
        string s(len - m, '1'); // Pad with '1's (which contribute no prime factors)
        
        // We only ever need to run this loop 'm' times (at most ~47 times!)
        for (int i = 0; i < m; i++) {
            for (int d = 1; d <= 9; d++) {
                vector<int> nextReq = subtractDigit(req, d);
                if (minDigits(nextReq) <= m - 1 - i) {
                    s += to_string(d);
                    req = nextReq;
                    break;
                }
            }
        }
        return s;
    }

public:
    string smallestNumber(string num, long long t) {
        vector<int> req = getPrimes(t);
        if (req.size() == 1 && req[0] == -1) return "-1";
        
        int n = num.size();
        
        // 1. Compute prefix requirements in O(N) time and store in a table
        // pref[i] holds the remaining prime factor requirements after keeping num[0...i-1]
        vector<vector<int>> pref(n + 1, vector<int>(4));
        pref[0] = req;
        
        int firstZero = -1;
        for (int i = 0; i < n; i++) {
            if (num[i] == '0') {
                firstZero = i;
                break;
            }
            pref[i + 1] = subtractDigit(pref[i], num[i] - '0');
        }
        
        // Check if num itself is already valid
        if (firstZero == -1 && minDigits(pref[n]) == 0) {
            return num;
        }
        
        // 2. Search right-to-left in O(N) time using instant pref[i] lookups
        int startIdx = (firstZero != -1) ? firstZero : n - 1;
        for (int i = startIdx; i >= 0; i--) {
            for (int d = (num[i] - '0') + 1; d <= 9; d++) {
                vector<int> nextReq = subtractDigit(pref[i], d);
                if (minDigits(nextReq) <= n - 1 - i) {
                    string prefix = num.substr(0, i) + to_string(d);
                    return prefix + buildSmallest(n - 1 - i, nextReq);
                }
            }
        }
        
        // 3. If no same-length answer exists, build the smallest string of length L
        int L = max(n + 1, minDigits(req));
        return buildSmallest(L, req);
    }
};