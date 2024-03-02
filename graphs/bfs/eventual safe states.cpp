// change the edge from u--->v to v--->u
// here as terminal state are having outdegree as 0 and in degree 1 we will reverse
// get all nodes with indegree 0 and remove edges on adjacent nodes
// all terminal nodes will have indegree of 0


class Solution {
  public:

    vector<int> eventualSafeNodes(int n, vector<int> adj[]) {
        // code here
        vector<int> adjRev[n];
        int indegree[n]={0};
        for(int i=0; i<n; i++) {
            for(auto it:adj[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }
        queue<int> q;
        vector<int> safeNodes;
        for(int i=0; i<n; i++) {
            if(indegree[i]==0) {
                q.push(i);
            }
        }
        
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);
            for(auto it: adjRev[node]) {
                indegree[it]--;
                if(indegree[it]==0) {
                    q.push(it);
                }
            }
        }
        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
    
};