// Last updated: 10/12/2026, 9:51:50 PM
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int count=0;
        sort(costs.begin(), costs.end());
        for(int i =0 ; i<costs.size() ; i++){
            if(costs[i] <=coins){
                coins-=costs[i];
                count++;
            }else{
                return count;
            }
        }
        return count;
    }
};