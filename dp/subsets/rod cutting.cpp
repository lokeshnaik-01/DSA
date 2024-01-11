#include<bits/stdc++.h>
using namespace std;
int f(int ind, int n, vector<int> &price, vector<vector<int>> &dp) {
	if(ind==0) {
		// at 0th index mean we can choose the rod of n units where is remaining cut
		return n*price[0];
	}
	if(dp[ind][n]!=-1) {
		return dp[ind][n];
	}
	int notPick = 0 + f(ind-1, n, price, dp);
	int pick = -1e9;
	if(ind+1<=n) {
		pick = price[ind] + f(ind, n-ind-1, price, dp);
	}
	return dp[ind][n] = max(pick,notPick);
}
int cutRod(vector<int> &price, int n)
{

	vector<vector<int>> dp(n, vector<int> (n+1, -1));
	return f(n-1, n, price, dp);
	// Write your code here.
}
