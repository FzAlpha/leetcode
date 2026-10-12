// Last updated: 10/12/2026, 9:53:22 PM
class Solution {
public:
    int minAddToMakeValid(string s) {
        int level = 0 , lowest = 0;
        for(char c : s){
            level += c == '(' ? 1 :-1;
            lowest = min(lowest , level);
        }
        return level -2 * lowest;
    }
};