// https://atcoder.jp/contests/dp/tasks/dp_b
#include <bits/stdc++.h>
using namespace std;
int recur(int ind, vector<int> v, vector<int> &dp, int k) {
    
    if(ind == 0) {
        return 0;
    }
    if(ind < 0) {
        return INT_MAX;
    }
    if(dp[ind]!=-1) {
        return dp[ind];
    }
    int ans = INT_MAX;
    for(int j=1; j<=k;j++) {
        if(ind<j) {
            continue;
        }
        ans = min(ans, recur(ind-j, v, dp,k) + abs(v[ind]-v[ind-j]));
    }
    dp[ind] = ans;
    return dp[ind];
}
int main()
{
    int n = 5;
    int k = 3;
    // frog can jump max of 0 to k units the find minimum enery to reach end
    vector<int> v = {10, 30, 40, 50, 20};
    vector<int> dp(n, -1);
    int ans = recur(n-1, v, dp,k);
    cout << ans << endl;
    for(auto it : dp) {
        cout << it << " ";
    }
}