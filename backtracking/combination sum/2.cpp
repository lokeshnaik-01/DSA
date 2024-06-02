// // https://leetcode.com/problems/combination-sum-ii/description/
class Solution {
public:
    void f(int ind, int target, vector<int> candidates, vector<int> path, vector<vector<int>> &ans) {
        if(target==0) {
            ans.push_back(path);
            return;
        }
        for(int i=ind; i<candidates.size(); i++) {
            if(i>ind&&candidates[i]==candidates[i-1]) {
                continue;
            }
            if(candidates[i] <= target) {
                path.push_back(candidates[i]);
                f(i+1, target-candidates[i], candidates, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> path;
        f(0, target, candidates, path, ans);
        return ans;
    }
};