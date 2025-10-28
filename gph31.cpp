// Shortest Path in Weighted undirected graph (GFG)


     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        
        vector<pair<int,int>>adj[n+1];
        
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int w=i[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});

        }

        set<pair<int,int>>st;
        vector<int>dist(n+1,1e9);
        vector<int>parent(n+1);

        
        st.insert({0,1});
        dist[1]=0;
        parent[1]=0;
        
        while(!st.empty()){
            auto front=*(st.begin());
            int node=front.second;
            int currDist=front.first;
            st.erase({currDist,node});
            
            for(auto i:adj[node]){
                int newNode=i.first;
                int newDist=i.second;
                
                if(newDist+currDist<dist[newNode]){
                    if(dist[newNode]!=1e9){
                        st.erase({dist[newNode],newNode});
                    }
                    
                    dist[newNode]=newDist+currDist;
                    parent[newNode]=node;
                    st.insert({dist[newNode],newNode});
                }
                
            }
            
        }
        
        vector<int>ans;
         int node = n;  
    if (dist[n] == 1e9) {  
        return {-1};  
    }
        while(node!=0){
            ans.push_back(node);
            node=parent[node];
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        
        return ans;
    }