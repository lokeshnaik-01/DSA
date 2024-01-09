// https://www.codingninjas.com/studio/problems/maze-obstacles_977241
#include<bits/stdc++.h>
using namespace std;
int mod=(int)(1e9+7);
int f(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp) {
    if(n>=0 && m>=0 && mat[n][m] == -1) {
        return 0;
    }
    if(m <0 || n<0) {
        return 0;
    }
    if(m==0&&n==0) {
        return 1;
    }
    if(dp[n][m]!=-1) {
        return dp[n][m];
    }
    int up = f(n-1, m, mat, dp);
    int left = f(n, m-1, mat, dp);
    return dp[n][m] = (left+up)%mod;
}
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n-1, m-1, mat, dp);
    // Write your code here
}
int main() {
    vector<vector<int>> points = {
        {0,0,0},
        {0,-1,0},
        {0,0,0}
    }
    cout << mazeObstacles(3,3,points);
    
}