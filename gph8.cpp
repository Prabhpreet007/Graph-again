
// Undirected Graph Cycle dfs  GFG

    //     bool dfs(int i,int parent,vector<int> adj[],vector<int>& vis){
    //     vis[i]=1;
        
    //     for(auto node:adj[i]){
    //         if(!vis[node]){
    //             if(dfs(node,i,adj,vis)==true){
    //                 return true;
    //             }
    //         }
    //         else if(node!=parent){
    //             return true;
    //         }
    //     }
    //     return false;
    // }
    

    // bool isCycle(int V, vector<int> adj[]) {
    //     vector<int>vis(V,0);
    //     for(int i=0;i<V;i++){
    //         if(!vis[i]){
    //             if(dfs(i,-1,adj,vis))return true;
    //         }
    //     }
    //     return false;
    // }