// Strongly Connected Components (Kosaraju's Algo)   (GFG) 


class Solution
{
	public:
	
	void dfs(int node,vector<vector<int>>& adj,vector<int>& vis,stack<int>& st){
	    vis[node]=1;
	    
	    for(auto it:adj[node]){
	        if(!vis[it])
	        dfs(it,adj,vis,st);
	    }
	    
	    st.push(node);
	}
	
	void dfs2(int node,vector<int>& vis,vector<vector<int>>& newAdj){
	    vis[node]=1;
	    
	    for(auto i:newAdj[node]){
	        if(!vis[i])
	        dfs2(i,vis,newAdj);
	    }
	}

    int kosaraju(int V, vector<vector<int>>& adj)
    {
        vector<int> vis(V,0);
        stack<int>st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,adj,vis,st);
            }    
        }
        vector<vector<int>>newAdj(V);
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                newAdj[it].push_back(i);
            }
        }
        
        for(int i=0;i<V;i++){
            vis[i]=0;
        }
        
        int cnt=0;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            
                if(!vis[node]){
                cnt++;
                dfs2(node,vis,newAdj);
                
            }
        }
        
        // return cnt;
        return cnt;
    }
};