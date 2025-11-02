// 1192. Critical Connections in a Network
// Tarjan's Algorithm


class Solution {
public:

    void dfs(int node,vector<int>&vis,vector<int>& dist,vector<int>& low,int parent,vector<vector<int>>& adj,int timer,vector<vector<int>>& ans){

        vis[node]=1;
        dist[node] = low[node] = timer++;

        for(auto i:adj[node]){
            if(i==parent){
                continue;
            }
            else if(!vis[i]){
                dfs(i,vis,dist,low,node,adj,timer,ans);
                low[node]=min(low[node],low[i]);
                if(dist[node]<low[i]){
                    ans.push_back({node,i});
                }
            }
            else{
                low[node]=min(dist[i],low[node]);
            }
            
        }


    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n);
        for(auto i:connections){
            int u=i[0];
            int v=i[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        int timer=0;
        vector<int>vis(n,0);
        vector<int>dist(n,-1);
        vector<int>low(n,-1);
        int parent = -1;

        vector<vector<int>> ans;

        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,dist,low,parent,adj,timer,ans);
            }
        }

        return ans;
    }
};