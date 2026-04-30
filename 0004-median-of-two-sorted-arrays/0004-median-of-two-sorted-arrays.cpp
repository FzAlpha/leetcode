// Fast I/O trick for LeetCode 0ms
static const int _ = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        
        if (m > n) {
            return findMedianSortedArrays(nums2, nums1);
        }
        
        int low = 0, high = m;
        int leftA, leftB, rightA, rightB;
        
        while (low <= high) {
            int cut1 = (low + high) / 2;
            int cut2 = (m + n + 1) / 2 - cut1;
            
            // INT_MIN aur INT_MAX use karne se better hai -1e9 aur 1e9 use karna
            leftA = (cut1 == 0) ? -1e9 : nums1[cut1 - 1];
            leftB = (cut2 == 0) ? -1e9 : nums2[cut2 - 1];
            
            rightA = (cut1 == m) ? 1e9 : nums1[cut1];
            rightB = (cut2 == n) ? 1e9 : nums2[cut2];
            
            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 != 0) {
                    return max(leftA, leftB);
                } else {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                }
            }
            else if (leftA > rightB) {
                high = cut1 - 1;
            }
            else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};


