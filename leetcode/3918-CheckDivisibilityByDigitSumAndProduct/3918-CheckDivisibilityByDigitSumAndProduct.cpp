// Last updated: 10/12/2026, 9:49:35 PM
class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0;
        int prod = 1;
        int x = n;
        while(x > 0){
            int digit = x % 10;
            sum+= digit;
            prod*= digit;
            x /= 10;
        }
        return n % (sum+prod) == 0;
    }
};