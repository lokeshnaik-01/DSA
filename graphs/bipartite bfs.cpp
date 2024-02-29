// we will have an visited array which will store the color of the node 
// while traversing in bfs is current node color is 0 then child node color will be 1
class Solution {
public:
    bool check(vector<int> &vis, vector<int> adj[], int start) {
        vis[start] = 0;
        
        queue<pair<int, int>> q;
	    q.push({start, 0});

	    while(!q.empty()) {
	        int node = q.front().first;
	        int color = q.front().second;
	        q.pop();
	        for(auto adjNodes: adj[node]) {
	            if(vis[adjNodes]==-1) {
	                q.push({adjNodes, !color});
	                vis[adjNodes]=!color;
	            }
	            else {
	                if(vis[adjNodes]==color) {
	                    return false;
	                }
	            }
	        }
	    }
	    return true;
    }
	bool isBipartite(int n, vector<int>adj[]){
	    // Code here
	    vector<int> vis(n, -1);
	    for(int i=0; i<n; i++) {
	        if(vis[i]==-1) {
	            if(!check(vis, adj, i)) {
	                return false;
	            }
	        }
	    }
	    return true;
	}

};