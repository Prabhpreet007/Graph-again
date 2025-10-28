// Shortest Distance in a Binary Maze (GFG)



int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
                         
            if (source.first == destination.first &&
            source.second == destination.second)
            return 0;
            
            queue<pair<int, pair<int, int>>> q;
            int n=grid.size();
            int m=grid[0].size();
            vector<vector<int>>dist(n,vector<int>(m,1e9));
            
            q.push({0,{source.first,source.second}});
            dist[source.first][source.second]=0;
            
            int dx[]={1,-1 ,0 ,0};
            int dy[]={0,0,-1,1};
            
            while(!q.empty()){
                auto front=q.front();
                q.pop();
                
                int currdist=front.first;
                int currR=front.second.first;
                int currC=front.second.second;
                
                for(int i=0;i<4;i++){
                    if((currR+dx[i])>=0 && (currR+dx[i])<n && (currC+dy[i])>=0 && (currC+dy[i])<m 
                    && grid[currR+dx[i]][currC+dy[i]]==1 && currdist + 1 < dist[currR+dx[i]][currC+dy[i]]){
                        if((currR+dx[i])==destination.first && (currC+dy[i])==destination.second){
                            return currdist+1;
                        }
                        
                        dist[currR+dx[i]][currC+dy[i]] = currdist + 1;
                        
                        q.push({currdist+1,{currR+dx[i],currC+dy[i]}});
                    }
                }
                
                
            }
            return -1;
    }