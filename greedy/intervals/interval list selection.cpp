// https://leetcode.com/problems/interval-list-intersections
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        // already first and second are sorted;
        int i=0;
        int j=0;
        int n = firstList.size();
        int m = secondList.size();
        while(i<n && j<m) {
            int st = max(firstList[i][0], secondList[j][0]); // max start point for intersection
            int end = min(firstList[i][1], secondList[j][1]); // min end point for intersection
            if(st <= end) {
                // common interval
                ans.push_back({st, end});
            }

            // if first interval is smaller than second interval then move first interval
            if(firstList[i][1] <= secondList[j][1]) {
                i++;
            }
            else {
                j++;
            }
        }
        return ans;
    }
};