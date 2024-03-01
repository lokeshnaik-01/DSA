class Solution {
  public:
    // Function to find the number of islands.
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>> grid) {
        vis[row][col] = 1;
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()) {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int delrow=-1; delrow<=1; delrow++) {
                for(int delcol=-1; delcol<=1; delcol++) {
                    int nrow = delrow+row;
                    int ncol = delcol + col;
                    if(nrow >=0 && ncol>=0 && nrow < grid.size() && ncol<grid[0].size() && vis[nrow][ncol]==0 && grid[nrow][col]=='1') {
                        q.push({nrow, ncol});
                        vis[nrow][ncol]=1;
                    }
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int c=0;
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m, 0));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                // perform bfs for each island
                if(vis[i][j]==0 && grid[i][j]=='1') {
                    c++;
                    bfs(i, j, vis, grid);
                }
            }
        }
        return c;
    }
};