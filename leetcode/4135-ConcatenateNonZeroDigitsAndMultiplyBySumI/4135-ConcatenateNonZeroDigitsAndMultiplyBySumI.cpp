// Last updated: 10/12/2026, 9:49:07 PM
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long b = 0;
        int sum = 0;
        long long p = 1; 
        
        while (n > 0) {
            int a = n % 10;
            
            
            if (a != 0) {
                b += (a * p);
                p *= 10;
            }
            
            sum += a;
            n /= 10;
        }
        
        return b * sum;
    }
};