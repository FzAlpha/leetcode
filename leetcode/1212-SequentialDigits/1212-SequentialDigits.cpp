// Last updated: 10/12/2026, 9:52:51 PM
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> result;
        string digits = "123456789";

        for (size_t len = 2; len <= digits.length(); ++len) {

            
            for (size_t i = 0; i <= digits.length() - len; ++i) {
                //string sub = digits.substr(i, len);
                int num = stoi(digits.substr(i, len));

                
                if (num >= low && num <= high) {
                    result.push_back(num);
                }
            }
        }
        return result;
    }
};