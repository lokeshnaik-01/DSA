// https://www.codingninjas.com/studio/problems/triangle_1229398
#include<bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp) {
	if(i==triangle.size()-1) {
		return triangle[i][j];
	}
	if(dp[i][j]!=-1) {
		return dp[i][j];
	}
	int down = triangle[i][j] + f(i+1, j, triangle, dp);
	int diagnol = triangle[i][j] + f(i+1, j+1, triangle, dp);
	return dp[i][j] = min(down, diagnol);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return f(0, 0, triangle, dp);
	// Write your code here.
}
int main() {
    vector<vector<int>> points = {
        {1},
        {5, 2},
        {1, 2, 1}
    }
    cout << ninjaTraining(points, 3);
    
}