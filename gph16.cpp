// Directed Graph Cycle(GFG)

    // bool dfs(int i,vector<int>& vis,vector<int>& pathVis,vector<int> adj[]){
    //     vis[i]=1;
    //     pathVis[i]=1;
        
    //     for(auto it:adj[i]){
    //         if(!vis[it]){
    //            if(dfs(it,vis,pathVis,adj)==true)return true; 
    //         }
    //         else if(pathVis[it]==1){
    //             return true;
    //         }
    //     }
        
    //     pathVis[i]=0;
    
    //     return false;
    // }
  
    // // Function to detect cycle in a directed graph.
    // bool isCyclic(int V, vector<int> adj[]) {
    //     vector<int>vis(V,0);
    //     vector<int>pathVis(V,0);
        
    //     for(int i=0;i<V;i++){
    //         if(!vis[i]){
    //             if(dfs(i,vis,pathVis,adj)==true)return true;
    //         }
    //     }
    //     return false;
        
    // }