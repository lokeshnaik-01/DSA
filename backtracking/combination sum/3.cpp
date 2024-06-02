// https://leetcode.com/problems/combination-sum-iii/description/
class Solution {
public:
    void f(int ind, int k, int n, vector<int> path, vector<vector<int>> &ans) {
        if(n==0 && path.size()==k) {
            ans.push_back(path);
            return;
        }
        for(int i=ind; i<=9; i++) {
            if(i<=n) {
                path.push_back(i);
                f(i+1, k, n-i, path, ans);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        f(1, k, n, path, ans);
        return ans;
    }
};