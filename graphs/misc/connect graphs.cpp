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
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int countExtras = 0;
        for(auto it: edge) {
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u)==ds.findUPar(v)) {
                countExtras++;
            }
            else {
                ds.unionBySize(u, v);
            }
        }
        int count=0;
        for(int i=0; i<n; i++) {
            if(ds.parent[i]==i) {
                count++;
            }
        }
        int ans = count-1;
        if(countExtras>=ans) {
            return ans;
        }
        return -1;
    }
};