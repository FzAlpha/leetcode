// Last updated: 10/12/2026, 9:51:54 PM
class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        unordered_map<string,string> d;
        for(auto& i:k){
            d[i[0]] = i[1];
        }
        string res;
        for(int i =0 ; i<s.size();++i){
            if(s[i] == '('){
                int j = s.find(")",i+1);
                auto t = s.substr(i+1,j-i-1);
                res+= d.count(t) ? d[t] : "?";
                i=j;
            }else{
                res+=s[i];
            }
        }
        return res;
    }
};