// City With the Smallest Number of Neighbors at a Threshold Distance(gfg and L.C)

int findCity(int n, int m, vector<vector<int>>& edges, int dT) {
        vector<vector<int>>arr(n,vector<int>(n,1e9));
        
        for(auto i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            arr[u][v]=wt;
            arr[v][u]=wt;
        }
        
        for (int i = 0; i < n; i++) {
        arr[i][i] = 0;
    }
        
        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    arr[i][j]=min(arr[i][j],arr[via][j]+arr[i][via]);
                }
            }
        }
        
        
        int mini=INT_MAX;
        int ind=0;
        for(int i=0;i<n;i++){
            int curr=0;
            for(int j=0;j<n;j++){
                if(arr[i][j]<=dT){
                    curr++;
                }
            }
            if(mini>=curr){
                mini=curr;
                ind=i;
            }
        }
        
        return ind;
        
    }
