// https://www.codingninjas.com/studio/problems/0-1-knapsack_920542
#include <bits/stdc++.h> 
using namespace std;
int f(int ind, int maxWeight, vector<int> weight, vector<int> value, vector<vector<int>> &dp) {
	if(ind == 0) {
		if(maxWeight >= weight[0]) {
			return value[0];
		}
		else {
			return 0;
		}
	}
	if(dp[ind][maxWeight]!=-1) {
		return dp[ind][maxWeight];
	}
	int notPick = 0+f(ind-1, maxWeight, weight, value, dp);
	int pick = -1e9;
	if(weight[ind] <= maxWeight) {
		pick = value[ind] + f(ind-1, maxWeight - weight[ind], weight, value, dp);
	}
	return dp[ind][maxWeight] = max(pick, notPick);
} 
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n, vector<int> (maxWeight+1, -1));
	return f(n-1, maxWeight, weight, value, dp);
	// Write your code here
}
int main() {
    vector<int> weight = {1, 2, 4, 5};
	vector<int> values = {5, 4, 8, 6};
	int maxWeight = 5;
	cout << knapsack(weight, values, maxWeight);
}