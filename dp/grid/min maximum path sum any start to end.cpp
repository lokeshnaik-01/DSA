// https://www.codingninjas.com/studio/problems/maximum-path-sum-in-the-matrix_797998
#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp) {
    if(j <0 || j>=matrix[0].size()) {
        return -1e9;
    }
    if(i==0) {
        return matrix[i][j];
    }
    if(dp[i][j]!=-1) {
        return dp[i][j];
    }
    int up = f(i-1, j, matrix, dp);
    int leftDiagnoal = f(i-1, j-1, matrix, dp);
    int rightDiagoal = f(i-1, j+1, matrix, dp);
    return dp[i][j] = max(up, max(leftDiagnoal, rightDiagoal)) + matrix[i][j];
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(), -1));
    int maxi = -1e9;
    int n = matrix.size();
    for(int i=0; i<matrix[0].size(); i++) {
        maxi = max(maxi, f(n-1, i, matrix, dp));
    }
    return maxi;
    //  Write your code here.
}
int main() {
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    }
    cout << getMaxPathSum(a);
    
}