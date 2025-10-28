

// T.C= O(N^2)+O(N^2)
// S.C = O(N^2)+O(4)+O(4)=O(N^2) APPROX

    // void findAns(int i,int j, vector<vector<int>>& vis,vector<vector<char>>& grid ){
    //     queue<pair<int,int>>q;
    //     q.push({i,j});
    //     vis[i][j]=1;

    //     while(!q.empty()){
    //         int row=q.front().first;
    //         int col=q.front().second;
    //         q.pop();

    //         int dx[]={1,-1,0,0};
    //         int dy[]={0,0,-1,1};

    //         for(int i=0;i<4;i++){
    //             int newR=row+dx[i];
    //             int newC=col+dy[i];

    //             if(newR>=0 && newR<grid.size() && newC>=0 && newC<grid[0].size() &&
    //               grid[newR][newC]=='1' && !vis[newR][newC]){
    //                 vis[newR][newC]=1;
    //                 q.push({newR,newC});
    //             }
    //         }
    //     }
    // }

    // int numIslands(vector<vector<char>>& grid) {
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<int>>vis(n,vector<int>(m,0));
    //     int cnt=0;
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(grid[i][j]=='1' && !vis[i][j]){
    //                 cnt++;
    //                 findAns(i,j,vis,grid);
    //             }
    //         }
    //     }
    //     return cnt;    
        
    // }