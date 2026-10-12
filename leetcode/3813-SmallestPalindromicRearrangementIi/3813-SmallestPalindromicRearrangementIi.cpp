// Last updated: 10/12/2026, 9:49:57 PM
class Solution {
    long long MAX = 1000001;

    long long nCr(int n , int k){
        if(k<0 || k>n) return 0 ;
        k = min(k,n-k);
        long long res = 1;
        for(int i =1 ; i<= k;i++){
            res = res * (n-i+1)/i;
            if(res >= MAX) return MAX;
        }
        return res;
    }
    long long nPr(vector<int>& freq){
        int total = 0;
        for(int f : freq) total += f;
        long long res =1;
        for(int f : freq){
            if(f ==0) continue;
            res *= nCr(total , f);
            if(res >= MAX) return MAX;
            total -=f;
        }
        return res;
    }
public:
    string smallestPalindrome(string s, int k) {
        vector<int> freq(26,0);
        for(char& c : s){
            freq[c-'a']++;
        }

        string mid ="";
        for(int i =0; i< 26; i++){
            if(freq[i]%2 != 0){
                mid = string(1, 'a'+i);
            }
            freq[i] /= 2;
        }
        if(nPr(freq) < k){
            return "";
        }
        int half = s.length() /2;
        string left = "";

        for(int i = 0; i<half ;i++){
            for(int c= 0; c< 26 ; c++){
                if(freq[c] == 0) continue;
                freq[c]--;
                long long ways = nPr(freq);
                if(k <= ways){
                    left += (char)('a'+c);
                    break;
                }else{
                    k -= ways;
                    freq[c]++;
                }
            }
        }
        string right(left.rbegin(),left.rend());
        return left+mid+right;
    }
};