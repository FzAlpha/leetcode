// Last updated: 10/12/2026, 9:49:38 PM
class Solution {
    int sumofdigits(int n) {
        std::string s = std::to_string(n);
        return std::accumulate(s.begin(), s.end(), 0, [](int sum, char ch) {
            return sum + (ch - '0');
        });
    }

public:
    int smallestIndex(vector<int>& A) {
        for (int i = 0; i < A.size(); i++) {
            std::cout<<sumofdigits(A[i]);
            if(i == sumofdigits(A[i])){
                return i;
            }
        }
        return -1;
    }
};