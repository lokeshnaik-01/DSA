#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, string s, string t, vector<vector<int>> &dp) {
	if(i<0 || j<0) {
		return 0;
	}
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	if(s[i] == t[j]) {
		return dp[i][j] = 1+f(i-1, j-1, s, t, dp);
	}
	else {
		int left = f(i-1, j, s, t, dp);
		int right = f(i, j-1, s, t, dp);
		return dp[i][j] = max(left, right);
	}
}
int lcs(string s, string t)
{
	int n = s.length();
	int m = t.length();
	//vector<vector<int>> dp(n, vector<int>(m, -1));
	//return f(i-1, j-1, s, t, dp);

	// we are doing this because in recursion i and j can be negative values
	vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
	for(int i=0; i<=n;i++) {
		for(int j=0; j<=m;j++) {
			if(i==0 || j==0) {
				dp[i][j] = 0;
			}
			else if(s[i-1] == t[j-1]) {
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}

    // print the substring
    int i=n, j=m;
	int len = dp[n][m];
	string ans = "";
    while(i>0 && j>0) {
		if(s[i-1]==t[j-1]) {
			ans+=s[i-1];
			i--;
			j--;
		}
		else if(dp[i-1][j] > dp[i][j-1]) {
			i--;
		}
		else {
			j--;
		}
	}
	return dp[n][m];
	//Write your code here
}