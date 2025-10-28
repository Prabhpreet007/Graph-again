
// Number Of Enclaves (GFG)


// void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<int>> &grid,int* r,int* c){
//       vis[i][j]=1;
//       int n=grid.size();
//       int m=grid[0].size();
//       for(int x=0;x<4;x++){
//           int row=i+r[x];
//           int col=j+c[x];
          
//           if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && grid[row][col]==1){
//               dfs(row,col,vis,grid,r,c);
//           }
//       }
      
//   }
//     int numberOfEnclaves(vector<vector<int>> &grid) {
//         int n=grid.size();
//         int m=grid[0].size();
//         vector<vector<int>>vis(n,vector<int>(m,0));
        
//         int r[]={-1,1,0,0};
//         int c[]={0,0,-1,1};
//         for(int i=0;i<m;i++){
//             if(grid[0][i]==1 && !vis[0][i]){
//                 dfs(0,i,vis,grid,r,c);
//             }
//             if(grid[n-1][i]==1 && !vis[n-1][i]){
//                 dfs(n-1,i,vis,grid,r,c);
//             }
//         }
        
//         for(int i=n-1;i>=0;i--){
//             if(grid[i][m-1]==1 && !vis[i][m-1]){
//                 dfs(i,m-1,vis,grid,r,c);
//             }
//             if(grid[i][0]==1 && !vis[i][0]){
//                 dfs(i,0,vis,grid,r,c);
//             }
//         }
//         int cnt=0;
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(grid[i][j]==1 && !vis[i][j]){
//                   cnt++;  
//                 }
//             }
//         }
//         return cnt;
        
//     }