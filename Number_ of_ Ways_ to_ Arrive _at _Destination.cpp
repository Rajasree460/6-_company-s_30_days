class Solution {
public:
    /*
        Approach: We will use the dijsktra algorithm to find out the shortest distance then calculate number of ways you can arrive at your destination in the shortest time. Take distance as long long
        1. Using a Priority Queue
        2. Using a Set
        3. Using a queue (not preferred)
    */
    #define P pair<long long,long long> 
    long long mod = 1e9 + 7;
    int dijkstra(vector<pair<int, int>> adj[], int n) {
        // Priority queue for relaxing nodes (distance, nodes)
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Distance vector
        vector<long long>distance(n, 1e15), path(n, 0);
        distance[0] = 0;
        pq.push({0, 0});
        path[0] = 1;

        while(!pq.empty()){
            int node = pq.top().second;
            long long dist = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it.first;
                long long edgeW = it.second;
                
                if(dist + edgeW < distance[adjNode]){
                    // Relax
                    distance[adjNode] = dist + edgeW;
                    path[adjNode] = path[node];
                    pq.push({distance[adjNode], adjNode});
                }else if(dist + edgeW == distance[adjNode]){
                    // Node is already visited with the shortes path, sum of parent and the current node path
                    path[adjNode] = (1LL*path[node] + 1LL*path[adjNode]) % mod;
                }
            }
        }
        return path[n - 1];
    }
    int countPaths(int n, vector<vector<int>>& roads) {
        
        
         // First step for grpah question is to create the adjacency list
        vector<pair<int, int>> adj[n];

        // Graph Creation
        for (auto &v : roads) {
            adj[v[0]].push_back({v[1], v[2]});
            adj[v[1]].push_back({v[0], v[2]});
        }
        
        return dijkstra(adj, n);
    }
};
