class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int n,int m, int src){
        // code here
        vector<int> adj[n];
        for(auto it:edges) {
            // two way connection
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(n, 1e9);
        queue<int> q;
        dist[src]=0;
        q.push(src);
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            for(auto it:adj[node]) {
                if(dist[node] +1 < dist[it]) {
                    // from current node to the adjacent node distance will be 1 itself
                    dist[it]=1+dist[node];
                    q.push(it);
                }
            }
        }
        for(int i=0; i<n; i++) {
            if(dist[i]==1e9) {
                dist[i]=-1;
            }
        }
        return dist;
    }
};