/*
khans algo is also called bfs of topological sort
find the indegree of all nodes 
next push nodes with indegree 0 into queue and take them out of queue and decrease the indegree of neighbour nodes which out the edges of the node
*/
vector<int> topoSort(int n, vector<int> adj[]) 
	{
	    vector<int> vis(n, 0);
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
	    while(!q.empty()) {
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        for(auto it:adj[node]) {
	            indegree[it]--;
	            if(indegree[it]==0) {
	                q.push(it);
	            }
	        }
	    }
	    return topo;
    }