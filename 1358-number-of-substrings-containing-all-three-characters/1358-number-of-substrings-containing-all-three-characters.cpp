class Solution {
public:
    int numberOfSubstrings(string s) {
        int lastA = -1;
        int lastB = -1;
        int lastC =-1;
        int count = 0;

        for(int i =0 ; i< s.length() ;i++){
            if(s[i] == 'a') lastA = i;
            if(s[i] == 'b') lastB = i;
            if(s[i] == 'c') lastC = i;

            if(min({lastA,lastB,lastC}) != -1){
                count+= min({lastA,lastB,lastC}) +1;
            }
        }
        return count;
    }
};