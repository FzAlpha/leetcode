// Last updated: 10/12/2026, 9:57:25 PM
class Solution {
public:
    int reverse(int n) {
        int rev = 0;
        while (n != 0){
            int dig = n%10;
            if(rev > INT_MAX/10 || rev < INT_MIN/10){
                return 0;
            }
            rev = rev * 10 + dig;
            n = n/ 10;
        }
        return rev;
    }
};