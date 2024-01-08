// https://www.codingninjas.com/studio/problems/maximum-sum-of-non-adjacent-elements_843261
#include <bits/stdc++.h> 
using namespace std;
int findSum(int ind, vector<int> nums, vector<int> &dp) {
    if(ind == 0) {
        dp[ind] = nums[0];
        return nums[ind];
    }
    if(ind < 0) {
        return 0;
    }
    if(dp[ind]!=-1) {
        return dp[ind];
    }
    // same as finding the sum of subsequence if we pick current index then we should skip to the last but 1 index
    int pick = nums[ind] + findSum(ind-2, nums, dp);
    // if current index is not picked then we skip to last index
    int notPick = 0 + findSum(ind-1, nums, dp);
    return dp[ind] = max(pick, notPick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
    return findSum(n-1, nums, dp);
    
}
int main() {
    vector<int> a= {9, 9, 8, 2};
    cout << maximumNonAdjacentSum(a);
    
}