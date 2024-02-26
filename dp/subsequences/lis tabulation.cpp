// https://www.codingninjas.com/studio/problems/longest-increasing-subsequence_630459
#include<bits/stdc++.h>
using namespace std;

int longestIncreasingSubsequence(int arr[], int n)
{
    vector<int> dp(n, 1);
    dp[0] = 1;
    int ans = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(arr[i] > arr[j]) {
                dp[i] = max(dp[i], 1+dp[j]);
                ans = max(ans, dp[i]);
            }
        }
    }
    return ans;
    // Write Your Code here
}