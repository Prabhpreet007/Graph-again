// 947. Most Stones Removed with Same Row or Column


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
    int removeStones(vector<vector<int>>& stones) {
        int row=0,col=0;
        for(auto i:stones){
            row=max(row,i[0]);
            col=max(col,i[1]);
        }

        DisjointSet ds(row+col+1);
        // row=row eg 0th row is 0
        // col=col+row+1 eg 0th row is 3 according to first testcase
        unordered_map<int,int>mp;
        for(auto i:stones){
            int currRow=i[0];
            int currCol=i[1]+row+1;
            ds.unionBySize(currRow,currCol);
            mp[currRow]++;
            mp[currCol]++;
        }

        set<int>st;
        for(auto i:mp){
            st.insert(ds.UltimateParent(i.first));
        }
        return stones.size()-st.size();

    }
};