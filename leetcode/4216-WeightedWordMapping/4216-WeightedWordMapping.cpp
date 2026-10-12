// Last updated: 10/12/2026, 9:49:02 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res ="";
        for(const auto& it : words){
            int sum =0 ;
            for(char c : it){
                sum += weights[c-'a'];
            }
            sum %= 26;
            res += ('z' - sum);
        }
        return res;
    }
};