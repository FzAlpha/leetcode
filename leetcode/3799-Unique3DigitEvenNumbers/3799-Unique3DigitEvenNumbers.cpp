// Last updated: 10/12/2026, 9:50:07 PM
class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> even;
        int n = digits.size();

        for(int i =0; i < n;i++){
            if(digits[i]== 0){
                continue;
            }
            for(int j = 0;j<n;j++){
                if(i == j){
                    continue;
                }
                for(int k =0;k < n;k++){
                    if(i== k || j == k){
                        continue;
                    }
                    if (digits[k] % 2 == 0) {
                        int num = (digits[i] * 100) + (digits[j] * 10) + digits[k];
                        even.insert(num);
                    }
                }
            }
        }
        return even.size();
    }
};