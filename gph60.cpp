// DIJKSTRA APPROACH (ESKO BINARY SEARCH AND DFS SE BHI SOLVE KIYA JAA SKTA HAI)
// Grid size: n * n

// Total nodes: n^2

// Har node ke 4 neighbors check honge. ek bar visit hoga har cell

// set me har insert/delete ka cost: log(n^2) = 2 * log(n) ≈ log(n)

// Time Complexity = O(n^2 * log n)

// Space Complexity = O(n^2)



class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();

        vector<vector<int>>dist(n,vector<int>(m,1e9));

        dist[0][0]=grid[0][0];

        set<pair<int,pair<int,int>>>st;
        st.insert({grid[0][0],{0,0}});

        int x[4]={0,0,1,-1};
        int y[4]={1,-1,0,0};

        while(!st.empty()){
            auto front=*(st.begin());
            int wt=front.first;
            int r=front.second.first;
            int c=front.second.second;
            st.erase(front);

            for(int i=0;i<4;i++){
                int newr=x[i]+r;
                int newc=y[i]+c;

                if(newr>=0 && newc>=0 && newr<n && newc<m && dist[newr][newc]>max(grid[newr][newc],wt)){
                    dist[newr][newc]=max(grid[newr][newc],wt);
                    st.insert({dist[newr][newc],{newr,newc}});
                }

            }

        }

        return dist[n-1][m-1];

    }
};