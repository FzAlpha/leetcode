// Last updated: 10/12/2026, 9:51:40 PM
class Solution {
public:
    vector<int> getConcatenation(vector<int>& n) {
        vector<int> res(2*n.size());
        std::copy(n.begin(),n.end(),res.begin());
        std::copy(n.begin(),n.end(),res.begin()+n.size());

        return res;
    }
};