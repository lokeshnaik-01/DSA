#include <bits/stdc++.h> 
// https://www.codingninjas.com/studio/problems/cost-to-cut-a-chocolate_3208460
// recursion
int f(int i, int j, vector<int> cuts) {
    if(i>j) {
        return 0;
    }
    int mini = INT_MAX;
    for(int ind=i; ind<=j; ind++) {
        int cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts) + f(ind+1, j, cuts);
        mini = min(cost, mini);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    // sorting because if cuts is {1,3,4,2} then if we start cutting at 4 then left sub problem is {1,3} whereas right is {2} but {2} is dependent on left

    sort(cuts.begin(), cuts.end());
    return f(1,c,cuts);
}

//memorization
// TC is O(n^3) because i and j both are change and we are looping over i and j so n
#include <bits/stdc++.h> 
int f(int i, int j, vector<int> cuts) {
    if(i>j) {
        return 0;
    }
    int mini = INT_MAX;
    for(int ind=i; ind<=j; ind++) {
        int cost = cuts[j+1] - cuts[i-1] + f(i, ind-1, cuts) + f(ind+1, j, cuts);
        mini = min(cost, mini);
    }
    return mini;
}
int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    // sorting because if cuts is {1,3,4,2} then if we start cutting at 4 then left sub problem is {1,3} whereas right is {2} but {2} is dependent on left

    sort(cuts.begin(), cuts.end());
    return f(1,c,cuts);
}

// tabulation

int cost(int n, int c, vector<int> &cuts){
    // Write your code here.
    cuts.push_back(0);
    cuts.push_back(n);
    vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
    // sorting because if cuts is {1,3,4,2} then if we start cutting at 4 then left sub problem is {1,3} whereas right is {2} but {2} is dependent on left
    sort(cuts.begin(), cuts.end());
    // in tabulation go from back
    // in recursion i is going from 1 to c where as j is going from c to 1 so in tabulation reverse
    for(int i=c; i>=1; i--) {
        for(int j=1; j<=c;j++) {
            if(i>j) {
                continue;
            }
            int mini = INT_MAX;
            for(int ind = i; ind<=j; ind++) {
                int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                mini = min(mini, cost);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}