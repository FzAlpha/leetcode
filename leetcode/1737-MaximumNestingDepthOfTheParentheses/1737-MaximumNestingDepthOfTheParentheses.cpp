// Last updated: 10/12/2026, 9:52:00 PM
class Solution {
public:
    int maxDepth(string s) {
        int max = 0;
        int count = 0;
        for(auto& it : s){
            if(it == '('){
                count++;
            }else if(it == ')'){
                count--;
            }
            max = std::max(max,count);
        }
        return max;
    }
};