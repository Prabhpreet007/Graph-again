// Articulation Point - I(GFG)

class Solution {
  public:
  
  void dfs(int node,int parent,vector<int>&tin,vector<int>&low,int &timer,
            vector<int>&vis,unordered_map<int,int>&mp,vector<int>adj[]){
        
        vis[node]=true;
        tin[node]=low[node]=timer++;
        int cnt=0;
        
        for(auto nbr:adj[node]){
            if(nbr==parent)continue;
            
            else if(!vis[nbr]){
                dfs(nbr,node,tin,low,timer,vis,mp,adj);
                low[node]=min(low[node],low[nbr]);
                if(parent!=-1 && low[nbr] >= tin[node]){
                    mp[node]++;
                }
                cnt++;

            }
            else{
                low[node]=min(low[node],tin[nbr]);
            }
            
            
        }
        
        if(cnt>1 && parent==-1){
            mp[node]++;
        }
        
  }
  
  
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        
        vector<int>tin(V,-1);
        vector<int>low(V,-1);
        int timer=1;
        vector<int>vis(V,0);
        unordered_map<int,int>mp;
        
        for(int i=0;i<V;i++){
            if (!vis[i])
            dfs(i, -1, tin, low, timer, vis, mp, adj);
}

        
        vector<int>ans;
        for(auto i:mp){
            ans.push_back(i.first);
        }
        if (ans.empty()) return {-1};
        sort(ans.begin(),ans.end());

        return ans;
        
    }
};