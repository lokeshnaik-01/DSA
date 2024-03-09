class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0]=0;
        pq.push({0,{0,0}});
        int delX[4] = {-1, 0, 1, 0};
        int delY[4] = {0, 1, 0, -1};
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;
            for(int i=0; i<4; i++) {
                int nX = row + delX[i];
                int nY = col + delY[i];
                if(nX>=0 && nX <n && nY>=0 && nY<m) {
                    int newEffort = max(abs(heights[row][col]-heights[nX][nY]), diff);
                    if(dist[nX][nY] > newEffort) {
                        dist[nX][nY] = newEffort;
                        pq.push({newEffort, {nX, nY}});
                    }
                }
            }
        }
        return dist[n-1][m-1];
    }
};