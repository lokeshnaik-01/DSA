class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfsCycleCheck(int node, vector<int> &vis, vector<int> adj[], vector<int> &path) {
        vis[node]=1;
        path[node]=1;
        
        for(auto it: adj[node]) {
            if(vis[it]==0) {
                if(dfsCycleCheck(it, vis, adj, path)==true) {
                    return true;
                }
            }
            else {
                if(path[it]==1) {
                    return true;
                }
            }
        }

        path[node]=0;
        return false;
    }
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        // path will have the path from ith node to the last node
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                if(dfsCycleCheck(i, vis, adj, path)==true) {
                    return true;
                }
            }
        }
        return false;
    }
};
