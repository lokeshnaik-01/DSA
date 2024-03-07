class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // dijkstra is used to find the shortest distance of all the vertices
        // priority queue is used {distance, node} will be used
        // nodes with less distance are present on top
        // we have another distance vector
        // {0,src_node} is pushed in the queue.
        // initially as distance from src_node to src_ is 0
        // get the nodes doing bfs and find distance is less than or eq to current node distance.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        pq.push({0, src});
        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it:adj[node]) {
                int edgeWeight = it[1];
                int adjNode = it[0];
                if(dis + edgeWeight < dist[adjNode]) {
                    dist[adjNode] = dis+edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
        
    }
};