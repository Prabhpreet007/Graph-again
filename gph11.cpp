// similar question prev one 
// 542. 01 Matrix (LEETCODE)

    // vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    //     int n=mat.size();
    //     int m=mat[0].size();

    //     queue<pair<pair<int,int>,int>>q;
    //     vector<vector<int>>dist(n,vector<int>(m,0));
    //     vector<vector<int>>vis(n,vector<int>(m,0));

    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(mat[i][j]==0){
    //                 q.push({{i,j},0});
    //                 vis[i][j]=1;
    //             }
    //         }
    //     }

    //     int arr1[]={-1,1,0,0};
    //     int arr2[]={0,0,-1,1};

    //     while(!q.empty()){
    //         int row=q.front().first.first;
    //         int col=q.front().first.second;
    //         int step=q.front().second;
    //         q.pop();
    //         dist[row][col]=step;

    //         for(int i=0;i<4;i++){
    //             int nr=row+arr1[i];
    //             int nc=col+arr2[i];

    //             if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0){
    //                 q.push({{nr,nc},step+1});
    //                 vis[nr][nc]=1;
    //             }
    //         }

    //     }
    //     return dist;
    // }