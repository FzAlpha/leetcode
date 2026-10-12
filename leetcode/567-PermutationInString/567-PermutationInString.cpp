// Last updated: 10/12/2026, 9:53:54 PM
class Solution {
public:
    bool isfreqsame(int freq1[],int freq2[]){
        for(int i = 0 ; i<26 ; i++){
            if( freq1[i] != freq2[i]){
                return false;
            }
        } 
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] ={0};
        for(int i =0; i< s1.length() ; i++){
            
            freq[s1[i] - 'a']++;
            
        }
         int windsize = s1.length();
        for(int i =0; i< s2.length(); i++){
            int windindx = 0,indx = i;
            int windfreq[26] = {0};
            while(windindx < windsize && indx < s2.size()){
                windfreq[s2[indx] - 'a']++;
                windindx++;indx++;
            }
            if(isfreqsame(freq,windfreq)){
                return true;
            }
        }
        return false;
    }
};