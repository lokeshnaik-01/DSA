
// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int ans = 0;
        for(int i=1; i<prices.size(); i++) {
            if(buy > prices[i]) {
                buy = prices[i];
            }

            ans = max(ans, prices[i]-buy);
        }
        return ans;
    }
};