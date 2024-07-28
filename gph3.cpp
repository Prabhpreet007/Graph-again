// T.C = O(N)+O(N)
// S.C = O(N)+O(V+2E)

    // void dfs(int i,vector<int>& vis,vector<int>* adj){
    //     vis[i]=1;

    //     for(auto nbr:adj[i]){
    //         if(!vis[nbr]){
    //             dfs(nbr,vis,adj);
    //         }
    //     }
    // }

    void bfs(int &i,vector<int>& vis,vector<int>* adj){
        queue<int>q;
        q.push(i);

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            vis[front]=1;


            for(auto nbr:adj[front]){
                if(!vis[nbr]){
                    q.push(nbr);
                }
            }
        }
    }
    

    int findCircleNum(vector<vector<int>>& arr) {
        int n=arr.size();
        // int m=arr[0].size();//

        vector<int>adj[n];

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                }
            }
        }

        int ans=0;
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i,vis,adj);
                ans++;
            }
        }
        return ans;
    }