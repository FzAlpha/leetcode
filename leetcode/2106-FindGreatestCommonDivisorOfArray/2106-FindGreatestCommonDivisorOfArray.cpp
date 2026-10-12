// Last updated: 10/12/2026, 9:51:35 PM
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int largest = 0;
        int smallest = 1001;
        for(auto& it : nums){
            if(it > largest){
                largest = it;
            }
            if (it < smallest){
                smallest = it;
            }
        }
        return __gcd(largest , smallest);
    }
};