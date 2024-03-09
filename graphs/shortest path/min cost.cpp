class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        int startX = source.first;
        int startY = source.second;
        int endX = destination.first;
        int endY = destination.second;
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        q.push({startX, {startY, 0}});
        dist[startX][startY]=0;
        int delX[4]={-1, 0, 1, 0};
        int delY[4]={0, -1, 0, 1};
        while(!q.empty()) {
            int curX = q.front().first;
            int curY = q.front().second.first;
            int dis = q.front().second.second;
            q.pop();
            for(int i=0; i<4; i++) {
                int nX = curX+delX[i];
                int nY = curY+delY[i];
                if(nX>=0 && nX<n && nY>=0 && nY<m && grid[nX][nY]==1) {
                    if(dist[nX][nY]>1+dis) {
                        dist[nX][nY]=1+dis;
                        q.push({nX, {nY, dist[nX][nY]}});
                    }
                }
            }
        }
        return dist[endX][endY]==1e9? -1 : dist[endX][endY];
    }
};