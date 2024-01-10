// https://www.codingninjas.com/studio/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494?
#include <bits/stdc++.h> 
using namespace std;
int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int x:arr) {
		sum+=x;
	}
	vector<vector<bool>> dp(n, vector<bool>(sum+1, false));
	for(int i=0; i<n;i++) {
		for(int target=0; target<=sum; target++) {
			// if no element is picked we can see sum will be 0 which is zero as possible
			if(target==0) {
				dp[i][target] = true;
			}
			else if(i==0 && arr[0] <= sum) {
				// base case
				// cause first element should be true if the value is less than target
				dp[i][arr[0]] = true;
			}
			else {
				bool notTake = dp[i-1][target];
				bool take = false;
				if(arr[i] <= target) {
					take = dp[i-1][target-arr[i]];
				} 
				dp[i][target] = take || notTake;
			}
		}
	}
	// the last row in dp which is dp[n-1][0....sum] wil tell us 
	// Write your code here.
	
	int mini = 1e9;
    // ideally we can only iterate for sum/2 times
	for(int j=0; j<=sum/2; j++) {
		if(dp[n-1][j]) {
			mini = min(mini, abs(sum-j-j));
		}
	}
	return mini;
}

int main() {
    vector<int> a = {4, 5, 6, 7};
    cout << minSubsetSumDifference(a, 4);
}