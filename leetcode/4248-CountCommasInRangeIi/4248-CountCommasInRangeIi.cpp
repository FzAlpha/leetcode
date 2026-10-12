// Last updated: 10/12/2026, 9:48:53 PM
class Solution {
public:
    long long countCommas(long long n) {
        long long K = 1000LL;
        long long M = 1000000LL;
        long long B = 1000000000LL;
        long long T = 1000000000000LL;
        long long Q = 1000000000000000LL;

        if (n < K) {
            return 0;
            
        } else if (n < M) {
            return (n - K) + 1;
            
        } else if (n < B) {
            return ((n - K) + 1) + 
                   ((n - M) + 1);
                   
        } else if (n < T) {
            return ((n - K) + 1) + 
                   ((n - M) + 1) + 
                   ((n - B) + 1);
                   
        } else if (n < Q) {
            return ((n - K) + 1) + 
                   ((n - M) + 1) + 
                   ((n - B) + 1) + 
                   ((n - T) + 1);
                   
        } else {
            return ((n - K) + 1) + 
                   ((n - M) + 1) + 
                   ((n - B) + 1) + 
                   ((n - T) + 1) + 
                   ((n - Q) + 1);
        }
    }
};