// Directed Graph Cycle (BFS) (TOPOLOGICAL SORT) (GFG)



    bool isCyclic(int V, vector<int> adj[]) {
        vector<int>inDeg(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                inDeg[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0)q.push(i);
        }
        
        int cnt=0;
        while(!q.empty()){
            auto front=q.front();
            q.pop();
            cnt++;
            
            for(auto i:adj[front]){
                inDeg[i]--;
                if(inDeg[i]==0)q.push(i);
            }
        }
        if(cnt!=V)return true;
        else return false;
    }