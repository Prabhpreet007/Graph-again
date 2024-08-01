// Replace O's with X's(GFG)

// void dfs(int i,int j,vector<vector<int>>& vis,vector<vector<char>>& board,int*dx,int*dy){
//         vis[i][j]=1;
//         int n=board.size();
//         int m=board[0].size();
//         for(int k=0;k<4;k++){
//             int row=dx[k]+i;
//             int col=dy[k]+j;
//             if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && board[row][col]=='O'){
//                 dfs(row,col,vis,board,dx,dy);
//             }
//         }

//     }

//     vector<vector<char>> fill(int n, int m, vector<vector<char>> board)
//     {
//         int dx[]={-1,1,0,0};
//         int dy[]={0,0,-1,1};

//         vector<vector<int>>vis(n,vector<int>(m,0));

//         for(int i=0;i<m;i++){
//             if(!vis[0][i] && board[0][i]=='O'){
//                 dfs(0,i,vis,board,dx,dy);
//             }
//             if(!vis[n-1][i] && board[n-1][i]=='O'){
//                 dfs(n-1,i,vis,board,dx,dy);
//             }
//         }

//         for(int i=0;i<n;i++){
//             if(!vis[i][0] && board[i][0]=='O'){
//                 dfs(i,0,vis,board,dx,dy);
//             }
//             if(!vis[i][m-1] && board[i][m-1]=='O'){
//                 dfs(i,m-1,vis,board,dx,dy);
//             }
//         }

//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 if(!vis[i][j] && board[i][j]=='O'){
//                     board[i][j]='X';
//                 }
//             }
//         }
//         return board;
//     }