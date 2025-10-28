// 733. Flood Fill (L.C)


// class Solution {
// public:
// bool isSafe(vector<vector<int>>& ans,int new_color,int old_color,map<pair<int,int>,bool>& vis,int x,int y){
// if(x>=0 && y>=0 && x<ans.size() && y<ans[0].size() && ans[x][y]==old_color && vis[{x,y}]==false){
//     return true;
// }
// else{
//     return false;
// }
// }

// void dfs(vector<vector<int>>& image,vector<vector<int>>& ans,int new_color,int old_color,map<pair<int,int>,bool>& vis,int x,int y){
// vis[{x,y}]=true;
// ans[x][y]=new_color;

// int dx[]={0,1,-1,0};
// int dy[]={1,0,0,-1};

// for(int i=0;i<4;i++){
//     int temp_x=x+dx[i];
//     int temp_y=y+dy[i];
//     if(isSafe(ans,new_color,old_color,vis,temp_x,temp_y)){
//         dfs(image,ans,new_color,old_color,vis,temp_x,temp_y);
//     }
// }
// }

// void bfs(vector<vector<int>>& image,vector<vector<int>>& ans,int &new_color,
//         int &old_color,map<pair<int,int>,bool>& vis,int &x,int &y){

//     queue<pair<int,int>>q;
//     q.push({x,y});
//         int dx[]={0,1,-1,0};
//         int dy[]={1,0,0,-1};
//     while(!q.empty()){
//         auto front=q.front();
//         q.pop();

//         vis[{front.first,front.second}]=true;
//         ans[front.first][front.second]=new_color;



//         for(int i=0;i<4;i++){
//         int temp_x=front.first+dx[i];
//         int temp_y=front.second+dy[i];
//         if(isSafe(ans,new_color,old_color,vis,temp_x,temp_y)){
//             q.push({temp_x,temp_y});
//         }
//     }
//     }
// }

//     vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
//         vector<vector<int>> ans=image;
//         int new_color=color;
//         map<pair<int,int>,bool> vis;
//         int old_color=image[sr][sc];
        
//         // dfs(image,ans,new_color,old_color,vis,sr,sc);
//             bfs(image,ans,new_color,old_color,vis,sr,sc);

//         return ans;   
//     }
// };