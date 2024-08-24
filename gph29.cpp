// DIJKSTRA ALGORITHM (GFG) (min heap)
// O(V logE)

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<int>dist(V,1e9);
        
        dist[S]=0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            int currdist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int nextNode=it[0];
                int nextDist=it[1];
                if(nextDist+currdist < dist[nextNode]){
                    dist[nextNode]=nextDist+currdist;
                    pq.push({dist[nextNode],nextNode});
                }
            }
            
        }
        return dist;
    }