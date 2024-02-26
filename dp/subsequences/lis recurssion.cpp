// https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459
#include<bits/stdc++.h>
using namespace std;
int f(int ind, int prev_ind, int n, int arr[], vector<vector<int>> &dp) {
    if(ind == n) {
        return 0;
    }
    if(dp[ind][prev_ind+1]!=-1) {
        dp[ind][prev_ind+1];
    }
    int notTake = 0 + f(ind+1, prev_ind, n, arr, dp);
    int take = 0;
    if(prev_ind == -1 || arr[ind] > arr[prev_ind]) {
        //take case;
        take = 1+f(ind+1, ind, n, arr, dp);
    }
    return dp[ind][prev_ind+1] = max(notTake, take);
}
int longestIncreasingSubsequence(int arr[], int n)
{
    vector<vector<int>> d(n, vector<int> (n+1, -1));
    
    // int ans = f(0, -1, n, arr, d);
    // return ans;

    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    for(int ind=n-1; ind>=0; ind--) {
        for(int prev_ind = ind-1; prev_ind>=-1; prev_ind--) {
            int notPick = dp[ind+1][prev_ind+1];
            int pick = 0;
            if(prev_ind==-1 || arr[ind] > arr[prev_ind]) {
                pick = 1+dp[ind+1][ind+1];
            }
            dp[ind][prev_ind+1] = max(pick, notPick);
        }
    }
    return dp[0][0];
    // Write Your Code here
}