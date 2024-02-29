class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool checkCycle(int src, vector<int> adj[], vector<int> &vis) {
        vis[src]=1;
        queue<pair<int, int>> q;
        // queue will store current node and it's parent node
        q.push({src, -1});
        while(!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for(auto adjNode: adj[node]) {
                if(vis[adjNode]==0) {
                    q.push({adjNode, node});
                    vis[adjNode] = 1;
                }
                else {
                    
                    // if node is already visited we check if the parent is equal to current adjNode
                    if(parent!=adjNode) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                if(checkCycle(i, adj, vis)){
                    return true;
                }
            }
        }
        return false;
        
    }
};