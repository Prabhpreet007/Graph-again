// 909. Snakes and Ladders
// T.C & S.C = O(n*n)


class Solution {
public:
    int n;
    
    pair<int,int> findRC(int num) {
    int r = (num - 1) / n;
    int c = (num - 1) % n;
    if (r % 2 == 1) c = n - 1 - c; // alternate rows reversed
    r = n - 1 - r; // bottom to top
    return {r, c};
}


    int snakesAndLadders(vector<vector<int>>& board) {
        n=board.size();
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        queue<int>q;
        int steps=0;

        q.push(1);
        vis[n-1][0]=true;

        while(!q.empty()){

            int qn=q.size();
            while(qn--){
                int front=q.front();
                if(front==n*n)return steps;
                q.pop();
                for(int i=1;i<=6 ;i++){
                    int curr=front+i;
                    if(curr>n*n)break;
                    auto newcell=findRC(curr);
                    int newr=newcell.first,newc=newcell.second;
                    
                    if(vis[newr][newc])continue;
                    vis[newr][newc]=true;
                    
                    if(board[newr][newc]==-1){
                        q.push(curr);
                        
                    }
                    else{
                        q.push(board[newr][newc]);
                    }
                }

            }
                steps++;
        }
        return -1;
    }
};