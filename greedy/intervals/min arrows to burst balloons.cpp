// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
class Solution {
public:
 // 1 6
 // 2 8
 // 7 12
 // 10 16
    static bool cmp(vector<int> a, vector<int> b) {
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ans = 1;
        // sort based on the end point of balloons.
        int start=points[0][0];
        int end = points[0][1];
        for(int i=1; i<points.size(); i++) {
            if(end >= points[i][0]) {
                // if next interval is in the range then we can burst this balloon as well
                end = min(end, points[i][1]);
            }
            else {
                ans++;
                // if not in range update start and end and we need extra balloon to shoot this
                start = points[i][0];
                end = points[i][1];
            }
        }
        return ans;
    }
};