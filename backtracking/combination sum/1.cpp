// https://leetcode.com/problems/combination-sum/description/
class Solution {
public:
    void findSum(vector<int>& candidates, int ind, int sum, int target, vector<vector<int>> &ans, vector<int> dummy) {
        if(sum == target) {
            ans.push_back(dummy);
            return;
        }
        else if(sum > target || ind == candidates.size()) {
            return;
        }
        else {
            dummy.push_back(candidates[ind]);
            findSum(candidates, ind, sum+candidates[ind], target, ans, dummy);
            dummy.pop_back();
            findSum(candidates, ind+1, sum, target, ans, dummy);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> dummy;
        vector<vector<int>> ans;
        findSum(candidates, 0, 0, target, ans, dummy);
        return ans;
    }
};