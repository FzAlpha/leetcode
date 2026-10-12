// Last updated: 10/12/2026, 9:53:03 PM
class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> lastseen(26 ,0);
        vector<bool> visited(26 , false);
        string res ="";

        for(int i =0 ; i< s.size() ; i++){
            lastseen[s[i] - 'a'] = i;
        }

        for(int i =0 ; i< s.size() ; i++){
            if(visited[s[i] - 'a']){
                continue;
            }
            while(!res.empty() && s[i] < res.back() && i < lastseen[res.back() - 'a']){
                visited[res.back() - 'a'] = false;
                res.pop_back();
            }
            res += s[i];
            visited[s[i]-'a'] = true;
        }
        return res;
    }
};