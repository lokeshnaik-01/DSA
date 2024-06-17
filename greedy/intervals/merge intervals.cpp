// https://leetcode.com/problems/merge-intervals
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        // sort by starting index
        int lowerBound = intervals[0][0];
        int upperBound = intervals[0][1];
        for(int i=1; i<intervals.size(); i++) {
            if(upperBound < intervals[i][0]) {
                // only merge if if start is greater than prev end
                ans.push_back({lowerBound, upperBound});
                lowerBound = intervals[i][0];
                upperBound = intervals[i][1];
            }
            else{
                upperBound = max(intervals[i][1], upperBound);
            }
        }
        ans.push_back({lowerBound, upperBound});
        return ans;
    }
};