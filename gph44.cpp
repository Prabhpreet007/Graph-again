// Number of Provinces (gfg)

// T.C =O(n^2)
class DisjointSet{
  public:
  vector<int>parent,size;
  
  DisjointSet(int n)
{
    parent.resize(n+1);
    size.resize(n+1,1);
    
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
}

    int findUltimate(int u){
    if(parent[u]==u){
        return u;
    }
    findUltimate(parent[u]);
    }

    void unionBySize(int a,int b){
        int u=findUltimate(a);
        int v=findUltimate(b);
        
        if(u==v)return;
        
        int sizeU=size[u];
        int sizeV=size[v];
        
        if(sizeU>sizeV){
            parent[v]=u;
            size[u]+=size[v];            
        }
        else{
            parent[u]=v;
            size[v]+=size[u];
        }
    }
    
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        DisjointSet ds(V);
        
        for(int i=0;i<V;i++){
            for(int j=0;j<V;j++){
                if(adj[i][j]==1){
                    ds.unionBySize(i,j);
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<V;i++){
            if(ds.parent[i]==i){
                ans++;
            }
        }
        return ans;
        
    }
};