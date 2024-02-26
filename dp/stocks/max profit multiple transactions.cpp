// https://www.codingninjas.com/studio/problems/selling-stock_630282
#include<bits/stdc++.h>
using namespace std;
long f(int ind, int buy, long *values, int n, vector<vector<long>> &dp) {
    if(ind == n) {
        return 0;
    }
    if(dp[ind][buy] != -1)  {
        return dp[ind][buy];
    }
    long profit = 0;
    // on a day user can buy or not buy
    if(buy) {
        // if stock needs to be bought
        // he needs to sells the next value
        // -values[ind] as profit = sold - bought
        long ch1 = -values[ind] + f(ind+1, 0, values, n, dp);

        // he didn't buy the stocks he can buy the stock on the next day
        long ch2 = 0 + f(ind+1, 1, values, n, dp);
        profit = max(ch1, ch2);
    }
    else {
        // if stocks need not be bough
        // he needs to sell the stock on the day and can buy stocks on the next day
        long ch3 = values[ind] + f(ind+1, 1, values, n, dp);
        // if he didn't sell he can sell it on the next day
        long ch4 = 0 + f(ind+1, 0, values, n, dp);
        profit = max(ch3, ch4);
    }
    return dp[ind][buy]=profit;
}
long getMaximumProfit(long *values, int n)
{
    vector<vector<long>> d(n, vector<long>(2,-1));
    // starting on 0th day user can buy stock
    // return f(0, 1, values, n, d);

    vector<vector<long>> dp(n+1, vector<long>(2,0));
    // as in base case we had ind==n so dp should be dp[n+1][2] size
    dp[n][0] = dp[n][1] = 0; //base case value
    for(int ind=n-1; ind>=0; ind--) {
        for(int buy = 0; buy <=1; buy ++) {
            long profit = 0;
            if(buy) {
                profit = max(-values[ind]+dp[ind+1][0], dp[ind+1][1]);
            }
            else {
                profit = max(values[ind]+dp[ind+1][1], dp[ind+1][0]);
            }
            dp[ind][buy] = profit;
        }
    }
    return dp[0][1];
    //Write your code here
}