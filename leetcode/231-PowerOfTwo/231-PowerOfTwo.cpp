// Last updated: 10/12/2026, 9:55:07 PM
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && (n & ( n-1)) == 0;
    }
};