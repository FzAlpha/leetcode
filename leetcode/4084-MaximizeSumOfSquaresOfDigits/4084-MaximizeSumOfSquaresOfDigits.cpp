// Last updated: 10/16/2026, 1:09:33 AM
class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(sum > 9*num){
            return "";
        }
        int nines = sum / 9, rest = sum % 9;
        return (string(nines, '9') + char('0' + rest) + string(num, '0')).substr(0, num);
    }
};