// https://www.codingninjas.com/studio/problems/ninja-s-training_3621003
#include<bits/stdc++.h>
using namespace std;
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp) {
    if(day == 0) {
        int maxi = 0;
        for(int task =0; task < 3;task++) {
            if(task!=last) {
                // we are passig the next day task which was performed 
                // this is done for last day
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) {
        return dp[day][last];
    }
    int maxi = 0;
    for(int task = 0; task < 3; task++) {
        if(task!=last) {
            int point = f(day-1, task, points, dp)+ points[day][task];
            maxi = max(point, maxi);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int> (4, -1));
    return f(n-1, 3, points, dp);
    // Write your code here.
}
int main() {
    vector<vector<int>> points = {
        {1, 2, 5},
        {3, 1, 1},
        {3, 3, 3}
    }
    cout << ninjaTraining(a);
    
}