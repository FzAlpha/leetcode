// Last updated: 10/12/2026, 9:52:52 PM
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n);
        for(int i = 0;i<n;i++){
            res[i] = (i ^ seq[i]) & 1;
        }
        return res;
    }
};