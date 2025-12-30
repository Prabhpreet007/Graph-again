// Undirected Graph Cycle bfs  GFG

//t.c=O(n+2E)
// s.c=O(n)

    // bool bfs(vector<int> adj[],vector<int>& vis,int node){
    //     queue<pair<int,int>>q;
    //     q.push({node,-1});
    //     vis[node]=1;
        
    //     while(!q.empty()){
    //         int fnode=q.front().first;
    //         int parent=q.front().second;q.pop();
            
    //         for(auto i: adj[fnode]){
    //             if(!vis[i]){
    //                 vis[i]=1;
    //                 q.push({i,fnode});
    //             }
    //             else if(i!=parent){
    //                 return true;
    //             }
    //         }
    //     }
    //     return false;
    // }
    
    // bool isCycle(int V, vector<int> adj[]) {
    //     vector<int>vis(V,0);
    //     for(int i=0;i<V;i++){
    //         if(!vis[i]){
    //             if(bfs(adj,vis,i))return true;
    //         }
    //     }
    //     return false;
    // }


    