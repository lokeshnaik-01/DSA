// https://www.codingninjas.com/studio/problems/palindrome-partitioning_873266
#include<bits/stdc++.h>
bool checkPalindrome(int i, int j,string s) {
    while(i<=j) {
        if(s[i++]!=s[j--]) {
            return false;
        }
    }
    return true;
}
int f(int ind, int n, string str, vector<int> &dp) {
    if(ind == n) {
        return 0;
    }
    if(dp[ind]!=-1) {
        return dp[ind];
    }
    int minCost = INT_MAX;
    for(int j = ind; j<n; j++) {
        
        if(checkPalindrome(ind, j, str)) {
            int cost = 1+f(j+1, n, str, dp);
            minCost = min(cost, minCost);
        }
    }
    return dp[ind] = minCost;
}
int palindromePartitioning(string str)
{
    int n = str.size();
    vector<int> dp(n+1, -1);
    // if ABC is given string then we patition at C also so remove 1
    return f(0, n, str, dp)-1;
    // Write your code here
}