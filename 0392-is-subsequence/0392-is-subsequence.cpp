class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1 == 0){
            return true;
        }
        if(n1>n2){
            return false;
        }
        int indx =0;
        for(int i =0 ; i<n2;i++){
            if(t[i] == s[indx]){
                indx++;
            }
            if(indx== n1){
                return true;
            }

        }
        return (indx ==n1);
    }
};