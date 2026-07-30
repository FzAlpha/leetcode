class Solution {
public:
    vector<string> result;

    void solve(int indx, string& digits, string& temp,
               unordered_map<char, string>& m) {
        if (indx >= digits.length()) {
            result.push_back(temp);
            return;
        }
        char ch = digits[indx];
        string str = m[ch];
        for (int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]);
            solve(indx + 1, digits, temp, m);
            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }
        // vector<string> result;
        unordered_map<char, string> m;
        m['2'] = "abc";
        m['3'] = "def";
        m['4'] = "ghi";
        m['5'] = "jkl";
        m['6'] = "mno";
        m['7'] = "pqrs";
        m['8'] = "tuv";
        m['9'] = "wxyz";

        string temp = "";
        solve(0, digits, temp, m);
        return result;
    }
};