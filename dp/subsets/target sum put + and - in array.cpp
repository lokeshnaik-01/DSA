// https://www.codingninjas.com/studio/problems/target-sum_4127362
#include <bits/stdc++.h> 
using namespace std;
int findWays(int ind, vector<int> arr, int target, vector<vector<int>> &dp) {
    if(ind == 0) {
        if(target==0&&arr[0]==0) {
            return 2;
        }
        if(target==0||arr[0]==target) {
            return 1;
        }
        return 0;
    }
    if(dp[ind][target]!=-1) {
        return dp[ind][target];
    }
    int notPick = findWays(ind-1, arr, target, dp);
    int pick = 0;
    if(arr[ind] <= target) {
        pick = findWays(ind-1, arr, target-arr[ind], dp);
    }
    int mod = 1e9+7;
    return dp[ind][target] = (pick+notPick)%mod;
}
int countPartitions(int n, int d, vector<int> arr) {
    int sum = 0;
    for(int x:arr) {
        sum+=x;
    }
    if(sum-d<0 || (sum-d)%2!=0) {
        return 0;
    }
    int s = (sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(s+1, -1));
    return findWays(n-1, arr, s, dp);
}
int targetSum(int n, int target, vector<int>& arr) {
    return countPartitions(n, target, arr);
    // this is the same as partition with given diff
    // we need to divide it into two subsets
    // https://www.codingninjas.com/studio/problems/partitions-with-given-difference_3751628
    // s1, s2
    // s1-s2 = diff

}