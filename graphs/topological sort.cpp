// linear ordering of vertices such that if there is an edge u & v, vertex u appears before v in that order
// topological sort if in directed acyclic graph only
class Solution
{
	public:
	void dfs(int node, vector<int> &vis, stack<int> &st, vector<int> adj[]) {
	    vis[node]=1;
	    for(auto it:adj[node]) {
	        if(vis[it]==0) {
	            dfs(it, vis, st, adj);
	        }
	    }
	    st.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> vis(n, 0);
	    stack<int> st;
	    for(int i=0; i<n; i++) {
	        if(vis[i]==0) {
	            dfs(i, vis, st, adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()) {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    // code here
	}
};