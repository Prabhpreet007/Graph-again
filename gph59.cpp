// 1905. Count Sub Islands

// BFS APPROACH
// T.C= O(n*m)

class Solution {
public:

    bool findAns(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int r,int c){
        queue<pair<int,int>>q;
        int n=grid1.size(),m=grid1[0].size();
        q.push({r,c});
        grid2[r][c]=-1;
        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};

        bool ans=true;

        while(!q.empty()){
            auto front=q.front();
            q.pop();
            int row=front.first;
            int col=front.second;
            
            if(grid1[row][col]!=1){
                ans=false;
            }

            for(int i=0;i<4;i++){
                int newr=row+x[i];
                int newc=col+y[i];

                if(newr>=0 && newr<n && newc>=0 && newc<m && grid2[newr][newc]==1){
                    grid2[newr][newc]=-1;
                    q.push({newr,newc});
                }
            }
        }

        return ans;

    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j]==1 && findAns(grid1,grid2,i,j)){
                    ans++;
                }
            }
        }
        return ans;
    }
};















// DISJOINT SET APPROACH



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
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int totalCells = n * m;
        DisjointSet dsu(totalCells);

        // Directions: up, down, left, right
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        // Step 1: Make unions for all connected 1s in grid2
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    int cell = i * m + j;
                    for (auto &[dx, dy] : dirs) {
                        int ni = i + dx, nj = j + dy;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < m && grid2[ni][nj] == 1) {
                            int neighbor = ni * m + nj;
                            dsu.unite(cell, neighbor);
                        }
                    }
                }
            }
        }

        // Step 2: Mark roots of all islands in grid2
        unordered_map<int, bool> islandValid;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1) {
                    int root = dsu.find(i * m + j);
                    islandValid[root] = true; // Initially mark as valid
                }
            }
        }

        // Step 3: Invalidate islands where grid1 has 0s
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && grid1[i][j] == 0) {
                    int root = dsu.find(i * m + j);
                    islandValid[root] = false; // Not a sub-island
                }
            }
        }

        // Step 4: Count valid islands
        int count = 0;
        for (auto &[root, valid] : islandValid) {
            if (valid) count++;
        }

        return count;
    }
};




