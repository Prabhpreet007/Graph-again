// Shortest path in Undirected Graph (GFG) (BFS)


    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        
        vector<int>adj[N];
        
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        
        vector<int>dist(N,1e9);
        dist[src]=0;
        
        queue<int>q;
        q.push(src);
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            for(auto it:adj[front]){
                if(dist[front]+1<dist[it]){
                    dist[it]=dist[front]+1;
                    q.push(it);
                }
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==1e9){
                dist[i]=-1;
            }   
        }
        return dist;
    }