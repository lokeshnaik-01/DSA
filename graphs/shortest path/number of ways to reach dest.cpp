class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<long long, long long>> adj[n];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }
        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        vector<int> dist(n, INT_MAX), ways(n, 0);
        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        int mod = (int)(1e9+7);
        while(!pq.empty()) {
            long long dis = pq.top().first;
            long long node = pq.top().second;
            pq.pop();
            for(auto it: adj[node]) {
                long long adjNode = it.first;
                long long edW = it.second;
                // it is the first time node reach with this short dist
                // so ways to reach that node is same as reaching the parent node
                if(dis+edW < dist[adjNode]) {
                    dist[adjNode] = dis+edW;
                    pq.push({dis+edW, adjNode});
                    ways[adjNode] = ways[node];
                }
                // if we reach with same distance then add the ways reached with current node
                else if(dis+edW == dist[adjNode]) {
                    ways[adjNode] = (ways[adjNode] + ways[node])%mod;
                }
            }
        }
        
        return int(ways[n-1]%mod);
    }
};