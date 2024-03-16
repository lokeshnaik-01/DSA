class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 0);
        for(int i=0; i<=n ;i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUPar(int node) {
        if(node == parent[node]) {
            return node;
        }
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        // after finding parents of nodes we check if the ranks are equal ot not
        // if the ranks are equal then return
        // if one if lower then connect lower parent to the higher parent
        // if the ranks are equal then attach how ever you want but make sure the rank of attached to it incremented
        if(ulp_v==ulp_u) {
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_u] = ulp_v;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_v==ulp_u) {
            return;
        }
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
  public:
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        // code here
        DisjointSet ds(n*m);
        int vis[n][m];
        memset(vis, 0, sizeof(vis));
        int count = 0;
        vector<int> ans;
        for(auto it: operators) {
            int row = it[0];
            int col = it[1];
            if(vis[row][col]==1) {
                ans.push_back(count);
                continue;
            }
            vis[row][col]=1;
            count++;
            vector<int> dr{-1, 0, 1, 0};
            vector<int> dc{0, -1, 0, 1};
            for(int i=0; i<4; i++) {
                int nrow = row+dr[i];
                int ncol = col+dc[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol < m) {
                    if(vis[nrow][ncol]==1) {
                        int nodeNo = row*m+col;
                        int adjNode = nrow*m+ncol;
                        if(ds.findUPar(nodeNo)!=ds.findUPar(adjNode)) {
                            count--;
                            ds.unionBySize(nodeNo, adjNode);
                        }
                    }
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};
