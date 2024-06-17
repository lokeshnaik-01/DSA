// https://leetcode.com/problems/non-overlapping-interval
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int ans = 0;
        int lastEnd = INT_MIN;
        for(auto interval: intervals) {
            if(lastEnd > interval[0]) {
                ans++;
                lastEnd = min(lastEnd, interval[1]);
            }
            else {
                lastEnd = interval[1];
            }
            cout << ans << " " << interval[0] << " " << interval[1] << " " << lastEnd << endl;
        }
        return ans;
    }
};