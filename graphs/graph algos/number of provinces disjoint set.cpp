class DisjointSet {
    vector<int> rank, parent, size;
public:
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

    int numProvinces(vector<vector<int>> adj, int V) {
        /*  code here
            number of provinces will have same parent
            1---->2   4---->5  6 7
            |
            3
            UltimateParent(1) = 1;
            UltimateParent(2) = 1;
            UltimateParent(3) = 1;
            UltimateParent(4) = 4;
            UltimateParent(5) = 4;
            UltimateParent(6) = 6;
            UltimateParent(7) = 7;
            We can say node having ultimate parent as itself will be a province
        */
        DisjointSet ds(V);
        for(int i=0; i<V; i++) {
            for(int j=0; j<V; j++) {
                if(adj[i][j]==1) {
                    ds.unionBySize(i, j);
                }
            }
        }
        int c = 0;
        for(int i=0; i<V; i++) {
            if(ds.findUPar(i)==i) {
                c++;
            }
        }
        return c;
    }
};