// Eventual Safe States (GFG) (BFS) (TOPO SORT)

    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int>adj2[V];
        vector<int>inDeg(V,0);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                adj2[it].push_back(i);
                inDeg[i]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        
        while(!q.empty()){
            
            int front=q.front();q.pop();
            ans.push_back(front);
            
            for(auto it:adj2[front]){
                inDeg[it]--;
                if(inDeg[it]==0){
                    q.push(it);
                }
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }



