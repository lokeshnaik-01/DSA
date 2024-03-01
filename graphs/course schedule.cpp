class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        //code here
        vector<int> adj[n];
	    for(auto it: prerequisites) {
	        adj[it[1]].push_back(it[0]);
	    }
	    vector<int> indegree(n, 0);
	    for(int i=0; i<n; i++) {
	        for(auto it:adj[i]) {
	            indegree[it]++;
	        }
	    }
	    queue<int> q;
	    for(int i=0; i<n; i++) {
	        if(indegree[i]==0) {
	            q.push(i);
	        }
	    }
	    vector<int> topo;
        // no need to store we can just use a counter
	    int c = 0;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        c++;
	        for(auto it:adj[node]) {
	            indegree[it]--;
	            if(indegree[it]==0) {
	                q.push(it);
	            }
	        }
	    }
	    if( c==n) {
	        return topo;
	    }
	    return {};
    }
};