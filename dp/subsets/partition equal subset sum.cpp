// https://www.codingninjas.com/studio/problems/subset-sum-equal-to-k_1550954
#include <bits/stdc++.h> 
using namespace std;
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
    if(target == 0) {
        return true;
    }
    if (ind == 0) {
        return target == arr[0];
    }
    if (dp[ind][target] != -1) {
        return dp[ind][target];
    }
    // consider the value at index and do not consider
    bool notTake = f(ind-1, target, arr, dp);
    bool take = false;
    if(arr[ind] <= target) {
        take = f(ind-1, target - arr[ind], arr, dp);
    }
    return dp[ind][target] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // we don't need to find the all subsequence it is given we only need to return true if there exists a sum
    // no need to use recursion to find all the subsequence
    // Write your code here.
    vector<vector<int>> dp(n, vector<int> (k+1, -1));
    return f(n-1, k, arr, dp);
}
int main() {
    vector<int> a = {2, 5, 1, 6, 7};
    cout << subsetSumToK(5, 4, a);
}