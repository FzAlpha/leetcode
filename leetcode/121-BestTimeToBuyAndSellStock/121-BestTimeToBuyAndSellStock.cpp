// Last updated: 10/12/2026, 9:55:39 PM
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 , bestBuy = prices[0];

        for(int i = 1;i<prices.size();i++){
            if(prices[i]>bestBuy){
                maxProfit = max(maxProfit, prices[i]- bestBuy);
            }
            bestBuy = min(bestBuy , prices[i]);
        }
        return maxProfit;
    }
};