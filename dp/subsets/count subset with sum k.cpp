// https://www.codingninjas.com/studio/problems/number-of-subsets_3952532
#include <bits/stdc++.h> 
using namespace std;
int f(int ind, int target, vector<int> arr, vector<vector<int>> &dp) {
	// we can have 0 in the array as well to handle the case we continue till index is 0;
	if(ind == 0) {
		if(target==0&&arr[0] == 0) {
			return 2;
		}
		if(arr[0] == target || target == 0) {
			return 1;
		}
		return 0;
	}
	if(dp[ind][target]!=-1) {
		return dp[ind][target];
	}
	int notPick = f(ind-1, target, arr, dp);
	int pick = 0;
	if(arr[ind] <= target) {
		pick = f(ind-1, target-arr[ind], arr, dp);
	}
	int mod = (int)(1e9+7);
	pick = pick%mod;
	notPick = notPick%mod;
	return dp[ind][target] = (pick+notPick)%mod;
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return f(n-1, k, arr, dp);
	// Write your code here.
}
int main() {
    vector<int> a = {4, 5, 6, 7};
    cout << minSubsetSumDifference(a, 4);
}