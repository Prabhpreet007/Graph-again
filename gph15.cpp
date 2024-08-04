// 785 IS GRAPH BIPARTITE (GFG)&(Leetcode)

// DFS APPROACH

    // bool dfs(int i,int clr,vector<int>adj[],vector<int>&color){
    //     color[i]=clr;
        
    //     for(auto it:adj[i]){
    //         if(color[it]==-1){
    //             if(dfs(it,!clr,adj,color)==false)return false;
    //         }
    //         else if(color[it]==color[i]){
    //             return false;
    //         }
    //     }
    //     return true;
    // }

	// bool isBipartite(int V, vector<int>adj[]){
    //     vector<int>color(V,-1);
        
    //     for(int i=0;i<V;i++){
    //         if(color[i]==-1){
    //             if(dfs(i,0,adj,color)==false){
    //                 return false;
    //             }
    //         }
    //     }
    //     return true;
	// }