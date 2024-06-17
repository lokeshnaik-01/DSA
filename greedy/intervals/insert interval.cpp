// https://leetcode.com/problems/insert-interval
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int lbound = newInterval[0];
        int ubound = newInterval[1];
        int n = intervals.size();
        for(int i=0; i<n; i++) {
            int start = intervals[i][0];
            int end = intervals[i][1];

            if(end<lbound) {
                ans.push_back(intervals[i]);
            }
            else if(start<=ubound || end<=ubound) {
                lbound = min(lbound, start);
                ubound = max(ubound, end);
            }
            else {
                ans.push_back({lbound, ubound});
                lbound = start;
                ubound = end;
            }
        }
        ans.push_back({lbound, ubound});
        return ans;
    }
};