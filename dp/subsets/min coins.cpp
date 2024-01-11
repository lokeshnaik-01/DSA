// https://www.codingninjas.com/studio/problems/minimum-elements_3843091
#include <bits/stdc++.h> 
using namespace std;
int f(int ind, int count, vector<int> &num, vector<vector<int>> &dp) {

    if(ind==0) {
        if(count % num[0] == 0) {
            return count/num[0];
        }
        return 1e9;
    }

    if(dp[ind][count]!=-1) {
        return dp[ind][count];
    }

    int notPick = 0+ f(ind-1, count, num, dp);
    int pick = 1e9;
    if(num[ind] <= count) {
		// here we have infinite number of coins so we do not move to prev index but consider current index
        pick = 1+f(ind, count-num[ind], num, dp);
    }
    return dp[ind][count] = min(pick, notPick);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n, vector<int> (x+1, -1));
    int ans = f(n-1, x, num, dp);
    if(ans >= 1e9) {
        return -1;
    }
    return ans;
    // Write your code here.
}
int main() {
    vector<int> a = {2, 1, 3};
    cout << canPartition(a, 4);
}