// Last updated: 10/12/2026, 9:50:13 PM
class Solution {
    int digitProduct(int x){
        int prod = 1;
        while(x>0){
            prod *= (x % 10);
            x /= 10;
        }
        return prod;
    }
public:
    int smallestNumber(int n, int t) {
        int x =n;
        while(digitProduct(x) % t != 0){
            x++;
        }
        return x;
    }
};