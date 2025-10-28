// Topological SORT BFS (KHAN'S ALGORITHM)

	vector<int> topoSort(int V, vector<int> adj[]) 
	{
        vector<int>inDeg(V);
        for(int i=0;i<V;i++){      //make sure to use 2 loops here and see how its iterating
            for(auto it:adj[i]){
            inDeg[it]++;
        }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(inDeg[i]==0)q.push(i);
        }
        
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();
            q.pop();
            
            ans.push_back(front);
            
            for(auto i:adj[front]){    //adj[front] important galti mt krna
                inDeg[i]--;
                if(inDeg[i]==0){
                    q.push(i);
                }
            }
        }
        return ans;
	}