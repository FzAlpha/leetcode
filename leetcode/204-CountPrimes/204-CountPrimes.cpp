// Last updated: 10/12/2026, 9:55:09 PM
class Solution {
public:
    int countPrimes(int n) {
        
        if (n <= 2) return 0;

      
        vector<bool> isprime(n, true);
        
      
        isprime[0] = false;
        isprime[1] = false;
        
        int count = 0;
        
        for (int i = 2; i < n; i++) {
            if (isprime[i]) {
                count++;
                
                
                for (long long j = (long long)i * i; j < n; j += i) {
                    isprime[j] = false;
                }
            }
        }
        
        return count;
    }
};
