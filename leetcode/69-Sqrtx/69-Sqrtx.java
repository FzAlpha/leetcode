// Last updated: 10/12/2026, 9:56:27 PM
class Solution {
    public int mySqrt(int x) {
        if (x ==0 ) return 0;
        else if(x<4) return 1; 

        int left = 1, right = x / 2;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;

            if (square == x) {
                return mid;
            } else if (square < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;        
    }
}