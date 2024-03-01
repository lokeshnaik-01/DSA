class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int node, int parent, vector<int> &vis, vector<int> adj[]) {
        vis[node] = 1;
        for(auto adjNode: adj[node]) {
            if(vis[adjNode]==0) {
                if(dfs(adjNode, node, vis, adj)==true) {
                    return true;
                }
            }
            else if(adjNode!=parent) {
                return true;
            }
        }
        return false;
    }
    bool isCycle(int n, vector<int> adj[]) {
        // Code here
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                if(dfs(i,-1, vis, adj)==true){
                    return true;
                }
            }
        }
        return false;
        
    }
};