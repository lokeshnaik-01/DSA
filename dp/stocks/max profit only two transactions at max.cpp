// https://www.codingninjas.com/studio/problems/buy-and-sell-stock_1071012
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int buy, int cap, int n, vector<int>& prices, vector<vector<vector<int>>> &dp) {
  if (ind == n) {
    return 0;
  }
  if(cap == 0) {
      return 0;
  }
  if (dp[ind][buy][cap]!= -1) {
    return dp[ind][buy][cap];
  }
  int profit = 0;
  if(buy) {
      // he can buy the stock on that day
      profit = max(-prices[ind]+f(ind+1, 0, cap, n, prices, dp),
                    0+f(ind+1, 1, cap, n, prices, dp));
  }
  else {
      // he needs to sell it so the cap needs to be decreased
      profit = max(prices[ind]+f(ind+1, 1, cap-1, n, prices, dp), // the stock is sold can buy next stock and cap is decreased by 1
                    0+f(ind+1, 0, cap, n, prices, dp)); // not sold next value can be sold
  }
  dp[ind][buy][cap] = profit;
}
int maxProfit(vector<int>& prices)
{
    int n = prices.size();
    int cap = 2;
    // if we can only buy 2 stocks then the values can be either 0 or 1 or 2
    // cap is also changing along with index and buy/sell options
    vector<vector<vector<int>>> d(n, vector<vector<int>> (2, vector<int> (cap+1, -1)));
    return f(0, 1, 2, prices.size(), prices, d);

    vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (cap+1, 0)));

    // base case cap == 0 it means ind and buy can be anything
    for(int ind=0; ind<=n; ind++) {
        for(int buy=0; buy <=1; buy++) {
            dp[ind][buy][0] = 0;
        }
    }

    // if ind==n it means buy and cap can be anything
    for(int buy =0; buy <=1; buy++) {
        for(int i=0; i<=cap; i++) {
            dp[n][buy][i] = 0;
        }
    }

    for(int ind=n-1; ind>=0; ind--) {
        for(int buy =0; buy <=1; buy ++) {
            for(int i=0; i<=cap; i++) {
                if(buy) {
                    dp[ind][buy][cap] = max(-prices[ind] + dp[ind+1][0][cap],
                                            0 + dp[ind+1][1][cap]);
                }
                else {
                    dp[ind][buy][cap] = max(prices[ind]+ dp[ind+1][1][cap-1],
                                            0+ dp[ind+1][0][cap]);
                }
            }
        }
    }
    return dp[0][1][cap];
    