// Last updated: 10/12/2026, 9:50:44 PM
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        unordered_set<int> s;
        int n = grid.size();
        long long totalCells = (long long)n * n;

        int a = -1;
        long long actualSum = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = grid[i][j];
                actualSum += val;

                if (s.find(val) != s.end()) {
                    a = val;
                }
                s.insert(val);
            }
        }

        long long expectedSum = (totalCells * (totalCells + 1)) / 2;

        int b = expectedSum - (actualSum - a);

        return {a, b};
    }
};
