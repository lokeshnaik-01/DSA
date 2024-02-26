class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ans) {
        vis[node] = 1;
        ans.push_back(node);
        for(auto it: adj[node]) {
            // get the adjacent node and immediately call the dfs for the node
            if(vis[it]==0) {
                dfs(it, adj, vis, ans);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        int n = V;
        vector<int> vis(n, 0);
        int start = 0;
        vector<int> ans;
        dfs(start, adj, vis, ans);
        return ans;
        // Code here
    }
};