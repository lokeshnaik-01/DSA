class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // set stores unique values and the smallest at the top and everything will be stored in ascending order
        // set will be used to erase already existing paths
        // it effects time complexity very less
        // st.erase() log(N) time complexity we can't explicitly say that which is better
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        st.insert({0, S});
        dist[S]=0;
        while(!st.empty()) {
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            for(auto it:adj[node]) {
                int adjNode = it[0];
                int edgW = it[1];
                if(dis+edgW<dist[adjNode]) {
                    if(dist[adjNode]!=1e9) {
                        //some one has reached the edge 
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis+edgW;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};