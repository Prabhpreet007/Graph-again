// Number of Distinct Islands

    // void dfs(int row,int col,vector<vector<int>>& vis,vector<vector<int>>& grid,
    // vector<pair<int,int>>& v,int parentR,int parentC){
    //     vis[row][col]=1;
        
    //     int n=grid.size();
    //     int m=grid[0].size();
        
    //     v.push_back({row-parentR,col-parentC});
        
    //     int dx[]={-1,1,0,0};
    //     int dy[]={0,0,-1,1};
        
    //     for(int i=0;i<4;i++){
    //         int nRow=row+dx[i];
    //         int nCol=col+dy[i];
            
    //         if(nRow>=0 && nCol>=0 && nRow<n && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]==1){
    //             dfs(nRow,nCol,vis,grid,v,parentR,parentC);
    //         }
    //     }
        
    // }
  
    // int countDistinctIslands(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
        
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     set<vector<pair<int,int>>>st;
        
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(!vis[i][j] && grid[i][j]==1){
    //                 vector<pair<int,int>> v;
    //                 dfs(i,j,vis,grid,v,i,j);
    //                 st.insert(v);
                    
    //             }
    //         }
    //     }
        
    //     return st.size();
    // }