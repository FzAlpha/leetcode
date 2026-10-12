// Last updated: 10/12/2026, 9:57:13 PM
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int rightPointer = height.size()-1,leftPointer = 0;

        while(leftPointer<rightPointer){
            int width = rightPointer - leftPointer;
            int ht = min(height[rightPointer],height[leftPointer]);
            int currWater = width * ht;

            maxWater = max(maxWater,currWater);
            height[leftPointer]<height[rightPointer] ? leftPointer++ : rightPointer--;
        }
        return maxWater;
    }
};