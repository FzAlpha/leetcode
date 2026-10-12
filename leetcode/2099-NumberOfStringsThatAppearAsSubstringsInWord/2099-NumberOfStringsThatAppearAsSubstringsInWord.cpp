// Last updated: 10/12/2026, 9:51:37 PM
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count =0;
        for(auto& p : patterns){
            if(word.find(p) != string::npos){
                count++;
            }
        }
        return count;
    }
};