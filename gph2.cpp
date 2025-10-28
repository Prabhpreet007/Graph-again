// BFS of graph GFG

// T.C=O(V+E)
// Vertices (V): The algorithm processes each vertex once, resulting in O(V) operations for vertex handling.
// Edges (E): The algorithm examines each edge once. Since BFS considers all adjacent vertices for each vertex, the total number of operations for edges is O(E).

    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        
        queue<int>q;
        vector<int>ans;
        
        vector<int>vis(V,0);
        q.push(0);
        vis[0]=1;
        
        while(!q.empty()){
            int front=q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto i:adj[front]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                }    
            }
        }
        return ans;
    
    }