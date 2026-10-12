// Last updated: 10/12/2026, 9:56:53 PM
class Solution {
public:
    int longestValidParentheses(auto& s) {
        int res = 0;
        vector<int> stack = {-1};
        
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stack.push_back(i);
            else {
                stack.pop_back();
                
                if (stack.empty())
                    stack.push_back(i);
                else
                    res = max(res, i - stack.back());
            }
        }
        
        return res;
    }
};