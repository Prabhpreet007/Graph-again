// 994. Rotting Oranges (l.c)

// class Solution {
// public:

// bool isSafe(vector<vector<int>>& temp,int x,int y){
// if(x>=0 && y>=0 && x<temp.size() && y<temp[0].size() && temp[x][y]==1){
//     return true;
// }
// else{
//     return false;
// }
// }
//     int orangesRotting(vector<vector<int>>& grid) {
//         int minTime=0;
//         queue<pair<pair<int,int>,int>> q;
//         vector<vector<int>> temp=grid;

//         for(int i=0;i<temp.size();i++){
//             for(int j=0;j<temp[0].size();j++){
//                 if(temp[i][j]==2){
//                     q.push({{i,j},0});
//                 }
//             }
//         }

//         while(!q.empty()){
//             auto frontNode=q.front();q.pop();

//             auto frontPair=frontNode.first;
//             int time=frontNode.second;
//             int x=frontPair.first;
//             int y=frontPair.second;

//             int dx[]={0,0,1,-1};
//             int dy[]={1,-1,0,0};

//             for(int i=0;i<4;i++){
//                 int new_x=dx[i]+x;
//                 int new_y=dy[i]+y;

//                 if(isSafe(temp,new_x,new_y)){
//                     q.push({{new_x,new_y},time+1});
//                     minTime=time+1;
//                     temp[new_x][new_y]=2;
//                 }
//             }
//         }



//         for(int i=0;i<temp.size();i++){
//             for(int j=0;j<temp[0].size();j++){
//                 if(temp[i][j]==1){
//                     return -1;
//                 }
//             }
//         } 
//         return minTime;
//     }
// };