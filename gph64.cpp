// 329. Longest Increasing Path in a Matrix


class Solution {
public:
    int DFS(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j){
        if(dp[i][j]!=0) return dp[i][j];
        int dx[4]={0,0,-1,1};
        int dy[4]={1,-1,0,0};
        int mx=1;
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(nx>=0&&ny>=0&&nx<grid.size()&&ny<grid[0].size()&&grid[nx][ny]>grid[i][j]){
                mx=max(mx,1+DFS(grid,dp,nx,ny));
            }
        }
        dp[i][j]=mx;
        return mx;
    }

    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        vector<vector<int>>dp(r,vector<int>(c,0));
        int ans=1;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans=max(ans,DFS(matrix,dp,i,j));
            }
        }
        return ans;
    }
};