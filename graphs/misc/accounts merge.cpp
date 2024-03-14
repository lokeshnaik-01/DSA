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
class Solution{
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &details) {
        // code here
        // map mail with the user
        // if already same mail is existed for the user then we can do unionBySize 
        unordered_map<string, int> mapMailNode;
        int n = details.size();
        DisjointSet ds(n);
        for(int i=0; i<n; i++) {
            for(int j=1; j<details[i].size(); j++) {
                string mail = details[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end()) {
                    mapMailNode[mail]=i;
                }
                else {
                    ds.unionBySize(i, mapMailNode[mail]);
                }
            }
        }
        
        vector<string> mergedMail[n];
        for(auto it: mapMailNode) {
            string mail = it.first;
            int node = ds.findUPar(it.second);
            mergedMail[node].push_back(mail);
        }
        vector<vector<string>> ans;
        for(int i=0; i<n; i++) {
            if(mergedMail[i].size()!=0) {
                sort(mergedMail[i].begin(), mergedMail[i].end());
                vector<string> temp;
                temp.push_back(details[i][0]);
                for(auto it: mergedMail[i]) {
                    temp.push_back(it);
                }
                ans.push_back(temp);
            }
        }
        return ans;
    }
};