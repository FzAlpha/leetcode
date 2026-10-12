// Last updated: 10/12/2026, 9:49:40 PM
class Solution {
public:
    int maxProduct(int n) {
        int largest = 0;
        int second_largest = 0;
        while(n != 0){
            int dig = n % 10;
            if (dig > largest){
                second_largest = largest;
                largest = dig;
            }else if(dig > second_largest){
                second_largest = dig;
            }
            n /= 10;
        }
        return largest * second_largest;
    }
};