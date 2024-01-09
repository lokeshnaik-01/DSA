// https://www.codingninjas.com/studio/problems/total-unique-paths_1081470
#include <bits/stdc++.h>
using namespace std;
int f(int m, int n, vector<vector<int>> &dp) {
	if(m==0 && n==0) {
		return 1;
	}
	if( m<0 || n <0) {
		return 0;
	}
	if(dp[m][n]!=-1) {
		return dp[m][n];
	}
    // we can only move right and bottom from 0,0 as we are doing bottom up i.e from m-1, n-1 we need to move up and left
	int left = f(m, n-1, dp);
	int up = f(m-1, n, dp);
	return dp[m][n] = left+up;
}
int uniquePaths(int m, int n) {
	// Write your code here.
	vector<vector<int>> dp(m, vector<int> (n, -1));
	return f(m-1, n-1, dp);
}
int main() {
    cout << uniquePaths(5,4);
    
}