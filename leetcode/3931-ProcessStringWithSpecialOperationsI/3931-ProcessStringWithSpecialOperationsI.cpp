// Last updated: 10/12/2026, 9:49:31 PM
class Solution {
public:
    string processStr(string s) {
        string res;
        for(const auto& it : s){
            if(it == '*'){
                if(!res.empty()){
                    res.pop_back();
                }
            }else if(it == '#'){
                res.reserve(res.size() *2);
                res += res;
            }else if(it == '%'){
                reverse(res.begin(),res.end());
            }else{
                res += it;
            }
        }
        return res;
    }
};