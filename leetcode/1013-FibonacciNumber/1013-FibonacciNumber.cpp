// Last updated: 10/12/2026, 9:53:11 PM
class Solution {
public:
    int fib(int n) {
        if(n==0 || n==1) return n;
        return fib(n-1)+fib(n-2);
    }
};