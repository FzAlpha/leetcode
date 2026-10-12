// Last updated: 10/12/2026, 9:52:47 PM
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        vector<vector<int>> results;
        int n = intervals.size();
        auto lambda = [](vector<int>& v1 , vector<int>& v2){
            if(v1[0] == v2[0]){
                return v1[1] > v2[1];
            }
            return v1[0] < v2[0];
        };
        sort(begin(intervals) , end(intervals) , lambda);
        results.push_back(intervals[0]);

        for(int i =0 ; i<n ; i++){
            if(results.back()[0] <= intervals[i][0] && results.back()[1] >= intervals[i][1]){
                continue;
            }
            results.push_back(intervals[i]);
        }
        return results.size();
        
    }
};