// https://www.codingninjas.com/studio/problems/ninja-and-his-friends_3125885
// https://www.youtube.com/watch?v=QGfn7JeXK54&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=14&ab_channel=takeUforward
#include<bits/stdc++.h>
using namespace std;
int f(int i, int j1, int j2, int r, int c, vector<vector<int>> & grid, vector<vector<vector<int>>> &dp) {
    // alice starts from 0,0
    // bob starts from 0,m-1
    // they do left diag, down, right down so i value will not change
    // for every move of alice bob can take 3 different possible moves if possible
    if(j1 < 0 || j2 < 0 || j1 >= c || j2 >= c) {
        return -1e8;
    }
    if(i==r-1) {
        // if both reach the last row then return
        if(j1==j2) {
            return grid[i][j1];
        }
        return grid[i][j1]+grid[i][j2];
    }

    if(dp[i][j1][j2]!=-1) {
        return dp[i][j1][j2];
    }
    int maxi = -1e8;
    // explore all path of alice and bob simultanously
    for(int dj1 = -1; dj1 < 2; dj1++) {
        for(int dj2 = -1; dj2 < 2; dj2++) {
            int value = 0;
            if(j1==j2) {
                value = grid[i][j1];
            }
            else {
                value = grid[i][j1] + grid[i][j2];
            }
            value += f(i+1, j1 + dj1, j2+dj2, r, c, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    // Write your code here.
    vector<vector<vector<int>>> dp(r, vector<vector<int>> (c, vector<int>(c, -1)));
    return f(0, 0, c-1, r, c, grid, dp);
}
int main() {
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    }
    cout << maximumChocolates(3, 3, points);
    
}