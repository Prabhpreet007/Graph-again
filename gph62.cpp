// 695. Max Area of Island


class DisjointSet {
public:
    vector<int> parent, size;

    DisjointSet(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;
        return parent[x] = find(parent[x]); // Path compression
    }

    void unite(int x, int y) {
        int px = find(x);
        int py = find(y);

        if (px == py) return;

        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }
};


class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        DisjointSet ds(n*m);
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};

        bool check=false; 
        //ye isly lgaya hai ki agr saare hi 0 hain grid me toh ds.size me toh initial value hum 1 dalte hain toh 
        // uski minimum value 1 hogi toh wo voi return krega isly agr check false hai means koi 1 aya hini 
        // and simply return 0

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    check=true;
                    int curind=(i*m)+j;
                    for(int ind=0;ind<4;ind++){
                        int nr=x[ind]+i,nc=y[ind]+j;
                        if(nr>=0 && nc>=0 && nr<n && nc<m && grid[nr][nc]){
                            int nbrind=nr*m+nc;
                            ds.unite(curind,nbrind);
                        }

                    }
                }
            }
        }
        if(check==false)return 0;
        int ans=0;
        for(auto i:ds.size){
            if(i>ans){
                ans=i;
            }
        }
        return ans;
    }
};