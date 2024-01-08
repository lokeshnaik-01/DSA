// https://www.codingninjas.com/studio/problems/house-robber_839733?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
long long findSum(int ind, vector<int> &valueInHouse, vector<long long> &dp) {
    if(ind == 0) {
        dp[0] = valueInHouse[0];
        return dp[0];
    }
    if(ind < 0) {
        return 0;
    }
    if(dp[ind]!=-1) {
        return dp[ind];
    }
    long long pick = valueInHouse[ind] + findSum(ind-2, valueInHouse, dp);
    long long notPick = 0 + findSum(ind-1, valueInHouse, dp);
    return dp[ind] = max(pick, notPick);
}
long long int houseRobber(vector<int>& valueInHouse)
{
    int n = valueInHouse.size();
    if(n==1) {
        return valueInHouse[0];
    }
    if(n<2) {
        return 0;
    }
    vector<int> t1, t2;
    for(int i=0; i<n;i++) {
        if(i!=0) {
            t1.push_back(valueInHouse[i]);
        }
        if(i!=n-1) {
            t2.push_back(valueInHouse[i]);
        }
    }
    // both first and last element can't be in same array so we discard either one of them only
    vector<long long> dp1(t1.size(), -1);
    long long ans1 = findSum(t1.size()-1, t1, dp1);
    vector<long long> dp2(t1.size(), -1);
    long long ans2 = findSum(t2.size()-1, t2, dp2);
    return max(ans1, ans2);
    // Write your code here.
}
int main() {
    vector<int> a= {9, 9, 8, 2};
    cout << houseRobber(a);
    
}