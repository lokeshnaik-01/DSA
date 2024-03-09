class Solution {
  public:
    int CheapestFLight(int n, vector<vector<int>>& flights, int src, int dst, int k)  {
        // Code here
        /* we cant implement dijkstras algo here as it takes greedy approach
        the number of stops will be reached and we can't reach
        instead of comparing with respective to distance we can compare it with respect to stops
        but as stops increase by 1 we can use normal queue*/
        queue<pair<int, pair<int, int>>> q;
        vector<int> dist(n, 1e9);
        vector<pair<int, int>> adj[n];
        for(auto it: flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        q.push({0, {src, 0}});
        dist[src]=0;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;
            if(stops > k) {
                continue;
            }
            for(auto iter: adj[node]) {
                int adjNode = iter.first;
                int edW = iter.second;
                if(cost+edW < dist[adjNode] && stops <=k) {
                    dist[adjNode] = cost+edW;
                    q.push({stops+1, {adjNode, cost+edW}});
                }
            }
        }
        if(dist[dst]==1e9) {
            return -1;
        }
        return dist[dst];
        
    }
};
