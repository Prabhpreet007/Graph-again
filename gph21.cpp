// 207. Course Schedule (LEETCODE)
// Prerequisite Tasks

	bool isPossible(int N,int P, vector<pair<int, int> >& prerequisites) {
	    vector<vector<int>> adj(N);
	    for(auto i:prerequisites){
	        int u=i.first;
	        int v=i.second;
	        
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
	    int cnt=0;
	    while(!q.empty()){
	        
	        auto front=q.front();q.pop();
	        cnt++;
	        
	        for(auto i:adj[front]){
	            inDeg[i]--;
	            if(inDeg[i]==0)q.push(i);
	        }
	    }
	    
	    if(cnt!=N)return false;
	    
	    else return true;
	}