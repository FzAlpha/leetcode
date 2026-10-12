// Last updated: 10/12/2026, 9:56:02 PM
class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {
        int indx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (a[i] >= b[j]) {
                a[indx--] = a[i--];
            } else {
                a[indx--] = b[j--];
            }
        }
        while (j >= 0) {
            a[indx--] = b[j--];
        }
    }
};