// Last updated: 10/12/2026, 9:54:36 PM
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& ma, int target) {
        int m = ma.size(), n = ma[0].size();
        int r = 0, c = n - 1;
        while (r < m && c >= 0) {
            if (target == ma[r][c]) {
                return true;
            } else if (target < ma[r][c]) {
                c--;
            } else {
                r++;
            }
        }
        return false;
    }
};