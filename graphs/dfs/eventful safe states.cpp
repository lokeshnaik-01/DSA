class Solution {
  public:
  bool dfsCycleCheck(int node, vector<int> &vis, vector<int> adj[], vector<int> &path, vector<int> &check) {
        vis[node]=1;
        path[node]=1;
        // check[node]=0;
        for(auto it: adj[node]) {
            if(vis[it]==0) {
                if(dfsCycleCheck(it, vis, adj, path, check)==true) {
                    return true;
                }
            }
            else {
                if(path[it]==1) {
                    return true;
                }
            }
        }
        check[node]=1;
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> vis(n, 0);
        vector<int> path(n, 0);
        vector<int> check(n, 0);
        vector<int> safeNode;
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                dfsCycleCheck(i, vis, adj, path, check);
            }
        }
        for(int i=0; i<n; i++) {
            if(check[i]) {
                safeNode.push_back(i);
            }
        }
        return safeNode;
    }
};