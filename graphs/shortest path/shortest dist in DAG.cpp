// we have part and the weight for a node
// first do the topo sort for the graph
// use the dfs method to store the topo sort in stack.
// create a distance array and mark the elements as INF;
// remove one by one element in the stack 
// go to nodes from popped node and and check if distance will be min(dist[adjNode], adj[Node][i][1]+dist[node])
class Solution {
  public:
    void topoSort(int node, vector<int> &vis, stack<int> &st, vector<pair<int, int>> adj[]) {
	    vis[node]=1;
	    for(auto it : adj[node]) {
	        if(vis[it.first]==0) {
	            topoSort(it.first, vis, st, adj);
	        }
	    }
	    st.push(node);
	}
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        // code here
        vector<pair<int, int>> adj[n];
        for(int i=0; i<m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        stack<int> st;
        vector<int> vis(n, 0);
        for(int i=0; i<n; i++) {
            if(vis[i]==0) {
                topoSort(i, vis, st, adj);
            }
        }
        vector<int> dist(n, 1e9);
        // we are considering source node to be 0
        dist[0]=0;
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            for(auto it:adj[node]) {
                int v = it.first;
                int wt = it.second;
                if(dist[node]+wt < dist[v]) {
                    dist[v] = dist[node]+wt;
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
