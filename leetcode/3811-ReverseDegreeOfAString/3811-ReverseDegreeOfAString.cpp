// Last updated: 10/12/2026, 9:50:01 PM
class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i = 0 ; i< s.length() ; i++){
            int a = 'z' - s[i] + 1;
            sum += (a * (i+1));
        }
        return sum;
    }
};