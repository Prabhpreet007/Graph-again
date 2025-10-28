//Prim's algorithm (used to find minimum spanning tree)
// Minimum Spanning Tree(GFG)

// T.C=O(E log E)

int spanningTree(int V, vector<vector<int>> adj[])
    {
        int ans=0;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>vis(V,0);
        pq.push({0,1});
        
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            
            if(vis[node]==1)continue;
            
            vis[node]=1;
            ans+=wt;
            
            for(auto i:adj[node]){
                int nWt=i[1];
                int nNode=i[0];
                
                if(!vis[nNode]){
                    pq.push({nWt,nNode});
                }
            }  
        }
        
        
        return ans;
    }