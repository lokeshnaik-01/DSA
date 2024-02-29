class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> dis(n, vector<int> (m, 0));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(mat[i][j]==0) {
                    // push all indices having 1 in queue and mark visited array as 1
                    q.push({{i, j}, 0});
                    vis[i][j] = 1;
                }
                else {
                    vis[i][j] = 0;
                }
            }
        }
        vector<int> delRow{-1, 0, 1, 0};
        vector<int> delCol{0, -1, 0, 1};
        while(!q.empty()) {
            int row = q.front().first.first;
            int col = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dis[row][col] = steps;
            for(int i=0; i<4; i++) {
                int nrow = row+delRow[i];
                int ncol = col+delCol[i];
                if(nrow >=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0) {
                    // if vis[nrow][ncol] is 0 then it means grid[nrow][ncol]=1
                    // so the steps to make it 1 are steps+1
                    vis[nrow][ncol] = 1;
                    q.push({{nrow, ncol}, steps+1});
                }
            }
        }
        return dis;
    }
};