// https://leetcode.com/problems/remove-covered-intervals/description/
class Solution {
public:
    // 1 4
    // 2 8
    // 3 6
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int lowerBound = intervals[0][0];
        int upperBound = intervals[0][1];
        int ans = 0;
        for(int i=1; i<intervals.size(); i++) {
            // if range between lower and upper bound just remove them
            if(intervals[i][0] >= lowerBound && intervals[i][1] <= upperBound) {
                ans++;
            }
            else if(intervals[i][0] == lowerBound && intervals[i][1] >= upperBound) {
                // if lower bound is same as start then merge and update upper bound
                ans++;
                upperBound = intervals[i][1];
            }
            else {
                // for all other cases no need to merge lowerbound is same as current index and upperbound as well
                lowerBound = intervals[i][0];
                upperBound = intervals[i][1];
            }
        }
        return intervals.size()-ans;
    }
};