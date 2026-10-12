// Last updated: 10/12/2026, 9:51:05 PM
class Solution {
public:
    int smallestEvenMultiple(int n) { 
        return n * (1 + n % 2);
    }
};