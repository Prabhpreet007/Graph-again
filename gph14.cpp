// 785 IS GRAPH BIPARTITE (LEETCODE)

// BFS APPROACH


// bool bfs(int i,vector<vector<int>>adj,vector<int>&color){
//         queue<int>q;
//         q.push(i);
//         color[i]=0;
        
//         while(!q.empty()){
//             int front=q.front();
//             q.pop();
            
//             for(auto it:adj[front]){
//                 if(color[it]==-1){
//                     color[it]=!color[front];
//                     q.push(it);
//                 }
//                 else if(color[it]==color[front]){
//                     return false;
//                 }
//             }
//         }
//         return true;
        
//     }

//     bool isBipartite(vector<vector<int>>& adj) {

//         int V=adj.size();
//         vector<int>color(V,-1);

//         for(int i=0;i<V;i++){
//             if(color[i]==-1){
//                 if(bfs(i,adj,color)==false){
//                     return false;
//                 }
//             }
//         }
//         return true;
// 	}