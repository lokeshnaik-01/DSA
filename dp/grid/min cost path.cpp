// https://www.codingninjas.com/studio/problems/minimum-path-sum_985349
#include<bits/stdc++.h>
using namespace std;
int f(int n, int m, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(n==0 && m==0) {
        return grid[0][0];
    }
    if(n <0 || m <0) {
        return (int)(1e9+7);
    }
    if(dp[n][m]!=-1) {
        return dp[n][m];
    }
    int up = f(n-1, m, grid, dp) + grid[n][m];
    int left = f(n, m-1, grid, dp) + grid[n][m];

    return dp[n][m] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, grid, dp);
}
int main() {
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    }
    cout << ninjaTraining(a);
    
}