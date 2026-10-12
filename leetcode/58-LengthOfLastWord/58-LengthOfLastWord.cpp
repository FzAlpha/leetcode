// Last updated: 10/12/2026, 9:56:22 PM
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = 0;
        bool isvalid = false;

        for (int i = s.length() - 1; i >= 0; --i) {
            if (!isalpha(s[i])) {
                if (isvalid)
                    return n;
            } else {
                n++;
                isvalid = true;
            }
        }

        return n;
    }
};