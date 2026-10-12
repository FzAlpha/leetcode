// Last updated: 10/12/2026, 9:50:03 PM
class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int cnt1 = count(s.begin(),s.end(),'1');

        vector<int> zero;
        int i = 0;
        while(i<n){
            int start = i;
            while(i<n && s[i] == s[start]){
                ++i;
            }
            if(s[start] == '0'){
                zero.push_back(i-start);
            }
        }
        int m = zero.size();
        if(m<2){
            return cnt1;
        }

        int bestGain = 0;
        for(int i =0 ;i < m-1 ; i++){
            bestGain = max(bestGain, zero[i]+zero[i+1]);
        }
        return cnt1+bestGain;
        
    }
};