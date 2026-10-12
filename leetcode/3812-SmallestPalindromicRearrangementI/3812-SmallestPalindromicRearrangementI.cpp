// Last updated: 10/12/2026, 9:49:58 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        string first = "";
        string middle = "";
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char current = i + 'a';
                first.append(freq[i] / 2, current);
                if (freq[i] % 2 != 0) {
                    middle = string(1, current);
                }
            }
        }
        string second(first.rbegin(), first.rend());
        return first + middle + second;
    }
};