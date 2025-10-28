// 827. Making A Large Island


class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i) {
            parent[i] = i;
        }
    }

    int UltimateParent(int n) {
        if (parent[n] == n) {
            return n;
        }
        return parent[n] = UltimateParent(parent[n]);
    }

    void unionBySize(int u, int v) {
        int pu = UltimateParent(u);
        int pv = UltimateParent(v);

        if (pu == pv)
            return;
        int uSize = size[pu];
        int vSize = size[pv];
        if (uSize < vSize) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

class Solution {
public:

    bool isValid(int row,int col,int size){
        return row>=0 && row<size && col>=0 && col <size;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0)
                    continue;

                int indexNo=row*n+col;    

                int x[4]={0,0,1,-1};
                int y[4]={1,-1,0,0};

                for(int i=0;i<4;i++){
                    int newR=x[i]+row;
                    int newC=y[i]+col;

                    if(isValid(newR,newC,n) && grid[newR][newC]==1){
                        int newIndexNo=newR*n+newC;
                        ds.unionBySize(indexNo,newIndexNo);
                    }
                }    
            }
        }

        int ans=0;

        // step 2 
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                if(grid[row][col]==1)continue;
                set<int>st;
                
                int x[4]={0,0,1,-1};
                int y[4]={1,-1,0,0};

                for(int i=0;i<4;i++){
                    int newR=x[i]+row;
                    int newC=y[i]+col;

                    if(isValid(newR,newC,n) && grid[newR][newC]==1){
                        int newIndexNo=newR*n+newC;
                        st.insert(ds.UltimateParent(newIndexNo));
                    }
                }

                int total=0;

                for(auto i:st){
                    total+=ds.size[i];
                }
                ans=max(ans,total+1);

            }
        }
        int total=0;
        for(int row=0;row<n;row++){
            for(int col=0;col<n;col++){
                total=max(total,ds.size[ds.UltimateParent(row*n+col)]);
            }
        }

        ans=max(ans,total);

        return ans;

    }
};