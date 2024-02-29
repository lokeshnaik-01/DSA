class Solution {
public:
    void dfs(int row, int col, int orgColor, int newColor, vector<vector<int>> &ans,vector<vector<int>> &image, vector<int> delRow, vector<int> delCol) {
        ans[row][col] = newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0; i<4; i++) {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            // we are modiying answer array instead of creating another visited array
            // we can check if image[nrow][ncol]==OrgColor and check in ans if the color is updated
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && image[nrow][ncol]==orgColor && ans[nrow][ncol]!=newColor) {
                dfs(nrow, ncol, orgColor, newColor, ans, image, delRow, delCol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Code here 
        int n = image.size();
        int m = image[0].size();
        int color = image[sr][sc];
        vector<vector<int>> ans = image;
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, -1, 0, 1};
        dfs(sr, sc, color, newColor, ans, image, delRow, delCol);
        return ans;
    }
};