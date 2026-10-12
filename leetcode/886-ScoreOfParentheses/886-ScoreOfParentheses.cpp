// Last updated: 10/12/2026, 9:53:20 PM
class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0, bal = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                bal++;
            } else {
                bal--;
                if (s[i - 1] == '(') {
                    ans += 1 << bal;
                }
            }
        }
        return ans;
    }
};