// Path With Minimum Effort(GFG)
// 1631. Path With Minimum Effort

// T.C = O(n∗m⋅log(n∗m))

    int MinimumEffort(int rows, int columns, vector<vector<int>> &heights) {
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        //make sure to check the priority queue declaration gadbad ho skti hai
        
        int n=heights.size();
        int m=heights[0].size();
        
        vector<vector<int>>dist(n,vector<int>(m,1e9));
        
        dist[0][0]=0;
        pq.push({0,{0,0}});
        
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        
        while(!pq.empty()){
            auto front=pq.top();pq.pop(); //its top not front
            
            int wt=front.first;
            int row=front.second.first;
            int col=front.second.second;
            
            if(row==n-1 && col==m-1){
                return wt;    
            }
            
            
            for(int i=0;i<4;i++){
                int nRow=row+dx[i];
                int nCol=col+dy[i];
                
                if(nRow>=0 && nCol>=0 && nRow<n && nCol<m){
                    int effort=max(wt,abs(heights[nRow][nCol]-heights[row][col]));
                    
                    if(dist[nRow][nCol]>effort){
                        dist[nRow][nCol]=effort;
                        pq.push({effort,{nRow,nCol}});
                    }
                }
            }
        }
    }