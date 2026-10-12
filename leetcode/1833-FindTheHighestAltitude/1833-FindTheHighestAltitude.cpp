// Last updated: 10/12/2026, 9:51:56 PM
class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int highest = 0;
        int curr = 0;
        for(int i = 0 ; i<gain.size() ; i++){
            curr+= gain[i];
            highest = max(highest , curr);
        }
        return highest;
    }
};