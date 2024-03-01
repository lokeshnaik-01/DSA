// we can use topological sort
// but topological is only used for DAG
// if topological sort has less than n elements it means it has cycle
class Solution {
  public:
    // Function to detect cycle in a directed graph.
      
    bool isCyclic(int n, vector<int> adj[]) {
        // code here
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
	    // vector<int> topo;
        // no need to store we can just use a counter
	    int c = 0;
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        // topo.push_back(node);
	        c++;
	        for(auto it:adj[node]) {
	            indegree[it]--;
	            if(indegree[it]==0) {
	                q.push(it);
	            }
	        }
	    }
	    return c!=n;
	    //return topo.size()!=n;
        
    }
};