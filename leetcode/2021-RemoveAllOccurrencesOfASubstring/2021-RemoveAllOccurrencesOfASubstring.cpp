// Last updated: 10/12/2026, 9:51:44 PM
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while(s.length() >0 && s.find(part) < s.length()){
            s.erase(s.find(part) , part.length());
        }
        return s;
    }
};