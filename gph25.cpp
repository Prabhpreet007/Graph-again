
// Shortest path in Directed Acyclic Graph (GFG)


    void topoSort(int i,vector<pair<int,int>>adj[],vector<int>&vis,stack<int>& st){
        vis[i]=1;
        
        for(auto it:adj[i]){
            if(!vis[it.first]){
                topoSort(it.first,adj,vis,st);
            }
        }
        st.push(i);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        
        vector<pair<int,int>>adj[N];
        
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int wt=edges[i][2];
            
            adj[u].push_back({v,wt});
        }
        
        vector<int>vis(N,0);
        stack<int>st;
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topoSort(i,adj,vis,st);
            }
        }
        vector<int>dis(N,1e9);
        int src=0;
        dis[src]=0;
        
        while(!st.empty()){
            int top=st.top();
            st.pop();
            
            for(auto it:adj[top]){
                int v=it.first;
                int wt=it.second;
                
                if(dis[top] + wt < dis[v]) {
                    dis[v] = dis[top] + wt;
                }
            }
        }
        
        for (int i = 0; i < N; i++) {
        if (dis[i] == 1e9) dis[i] = -1;
      }
      
        return dis;
        
    }