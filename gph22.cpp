// Course Schedule(GFG)

vector<int> findOrder(int N, int m, vector<vector<int>> prerequisites) 
    {
        vector<vector<int>> adj(N);
	    for(auto i:prerequisites){
	        int u=i[0];
	        int v=i[1];
	        
	        adj[v].push_back(u);
	    }
	    
	    vector<int>inDeg(N,0);
	    
	    queue<int>q;
	    for(int i=0;i<N;i++){
	        for(auto it:adj[i]){
	            inDeg[it]++;
	        }
	    }
	    for(int i=0;i<N;i++){
	        if(inDeg[i]==0){
	            q.push(i);
	        }
	    }
	    vector<int>ans;
	    while(!q.empty()){
	        
	        auto front=q.front();q.pop();
	        ans.push_back(front);
	        
	        for(auto i:adj[front]){
	            inDeg[i]--;
	            if(inDeg[i]==0)q.push(i);
	        }
	    }
	    if(ans.size()!=N)return {};
	    
	    else return ans;
    }