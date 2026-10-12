// Last updated: 10/12/2026, 9:56:30 PM
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& ma) {
        if (ma.empty())
            return {};

        int m = ma.size(), n = ma[0].size();
        int srow = 0, scol = 0;
        int erow = m - 1, ecol = n - 1;
        vector<int> ans;

        while (srow <= erow && scol <= ecol) {

            for (int j = scol; j <= ecol; j++) {
                ans.push_back(ma[srow][j]);
            }
            srow++;

            for (int i = srow; i <= erow; i++) {
                ans.push_back(ma[i][ecol]);
            }
            ecol--;

            if (srow <= erow) {
                for (int j = ecol; j >= scol; j--) {
                    ans.push_back(ma[erow][j]);
                }
                erow--;
            }

            if (scol <= ecol) {
                for (int i = erow; i >= srow; i--) {
                    ans.push_back(ma[i][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};
