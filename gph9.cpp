// Distance of nearest cell having 1 (GFG)

    // vector<vector<int>> nearest(vector<vector<int>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>>dist (n,vector<int>(m,0));
    //     vector<vector<int>>vis (n,vector<int>(m,0));
    //     queue<pair<pair<int ,int> ,int>>q;
        
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]==1){
    //                 q.push({{i,j},0});
    //                 vis[i][j]=1;
    //             }
    //         }
    //     }
    //     int arrRow[]={1,-1,0,0};
    //     int arrCol[]={0,0,-1,1};
    //     while(!q.empty()){
    //         int row=q.front().first.first;
    //         int col=q.front().first.second;
    //         int steps=q.front().second;
    //         q.pop();
            
    //         dist[row][col]=steps;
            
            
            
    //         for(int i=0;i<4;i++){
    //             int nRow=row+arrRow[i];
    //             int nCol=col+arrCol[i];
                
    //             if(nRow>=0 && nRow<n && nCol>=0 && nCol<m && vis[nRow][nCol]==0){
    //                 q.push({{nRow,nCol},steps+1});
    //                 vis[nRow][nCol]=1;
    //             }
    //         }
    //     }
    //     return dist;
        
    // }