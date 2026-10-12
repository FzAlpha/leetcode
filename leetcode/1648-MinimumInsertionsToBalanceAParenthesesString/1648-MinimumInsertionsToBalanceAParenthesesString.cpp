// Last updated: 10/12/2026, 9:52:06 PM
class Solution {
public:
    int minInsertions(string s) {
        int a = 0 , b = 0;
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] == '(') a++;
            else{
                if(i+1 < s.size() && s[i+1] == ')') i++;
                else b++;
                if(a>0) a--;
                else b++;
            }
        }
        return b+a*2;
    }
};