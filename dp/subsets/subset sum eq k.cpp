// https://www.codingninjas.com/studio/problems/partition-equal-subset-sum_892980
#include <bits/stdc++.h> 
using namespace std;
bool f(int ind, int target, vector<int> &arr, vector<vector<int>> &dp) {
	if(target == 0) {
		return true;
	}
	if(ind == 0) {
		return target == arr[0];
	}
	if(dp[ind][target]!=-1) {
		return dp[ind][target];
	}
	bool notTake = f(ind-1, target, arr, dp);
	bool take = false;
	if(arr[ind] <= target) {
		take = f(ind-1, target-arr[ind], arr, dp);
	}
	return dp[ind][target] = notTake || take;
}
bool canPartition(vector<int> &arr, int n)
{
	int s=0;
	for(int x:arr) {
		s+=x;
	}
	// if sum is odd then we can't divide the sub array
	if(s&1) {
		return false;
	}
	int k = s/2;
	// we can find subset with sum as s/2 then it is sure that remaining subset will also have sum s/2
	vector<vector<int>> dp(n, vector<int> (k+1, -1));
	return f(n-1, k, arr, dp);

// tabulation
	int sum = 0;
	for(int x:arr) {
		sum+=x;
	}
	if(sum&1) {
		return false;
	}
	sum = sum/2;
	vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	for(int i=0; i<n;i++) {
		for(int target=0; target<=sum; target++) {
			if(target==0) {
				dp[i][target] = true;
			}
			else if(i==0 && arr[0] <= sum) {
				dp[i][arr[0]] = true;
			}
			else {
				bool notTake = dp[i-1][target];
				bool take = false;
				if(a[i] <= target) {
					take = dp[i-1][target-a[i]];
				} 
				dp[i][target] = take || notTake;
			}
		}
	}
	return dp[n-1][sum];
	// tabulation also fills the value
	//   
	// Write your code here.
}
int main() {
    vector<int> a = {4, 5, 6, 7};
    cout << canPartition(a, 4);
}