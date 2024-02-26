// https://www.codingninjas.com/studio/problems/problem-name-boolean-evaluation_1214650
#include<bits/stdc++.h>
int M = 1e9+7;
#define ll long long
ll f(int i, int j, int isTrue, string exp, vector<vector<vector<ll>>> &dp) {
    if(i>j) {
        return 0;
    }
    if(dp[i][j][isTrue]!=-1) {
        return dp[i][j][isTrue];
    }
    if(i==j) {
        if(isTrue) {
            return exp[i] == 'T';
        }
        else {
            return exp[i] == 'F';
        }
    }
    
    ll ways = 0;
    for(int ind=i+1; ind<=j-1; ind+=2) {
        // find all the left cases and right cases
        // we find all the cases if isTrue is 1 or 0
        ll lT = f(i, ind-1, 1, exp, dp);
        ll lF = f(i, ind-1, 0, exp, dp);
        ll rT = f(ind+1, j, 1, exp, dp);
        ll rF = f(ind+1, j, 0, exp, dp);
        
        if (exp[ind] == '&') {
            if(isTrue) {
                ways = (ways + (rT*lT)%M)%M;
            }
            else {
                ways = (ways + (rT*lF)%M + (rF*lT)%M + (rF*lF)%M)%M;
            }
        } 
        else if (exp[ind] == '|') {
            if(isTrue) {
                ways = (ways + (lT*rT)%M + (rT*lF)%M + (rF*lT)%M)%M;
            }
            else {
                ways = (ways + (rF*lF)%M)%M;
            }
        }
        else {
            if(isTrue) {
                ways = (ways + (lT*rF)%M + (lF*rT)%M)%M;
            }
            else {
                ways = (ways + (rT*lT)%M + (rF*lF)%M)%M;
            }
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) {
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<ll>>> dp(n, vector<vector<ll>> (n, vector<ll> (2, -1)));
    return int(f(0, exp.size()-1, 1, exp, dp));
}