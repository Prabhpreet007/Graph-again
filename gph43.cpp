// KRUSKAL'S ALGORITHM (MINIMUM SPANNING TREE)

// Minimum Spanning Tree(GFG)

// T.C = O(ElogE)+O(Eα(V))

class DisjointSet
{
public:
    vector<int> parent, size;
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; ++i)
        {
            parent[i] = i;
        }
    }

    int UltimateParent(int n)
    {
        if (parent[n] == n)
        {
            return n;
        }
        return parent[n] = UltimateParent(parent[n]);
    }

    void unionBySize(int u, int v)
    {
        int pu = UltimateParent(u);
        int pv = UltimateParent(v);

        if (pu == pv)
            return;
        int uSize = size[pu];
        int vSize = size[pv];
        if (uSize < vSize)
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};

int spanningTree(int V, vector<vector<int>> adj[])
{
    vector<pair<int, pair<int, int>>> edge;

    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            int node = i;
            int reachNode = it[0];
            int wt = it[1];
            edge.push_back({wt, {node, reachNode}});
        }
    }

    sort(edge.begin(), edge.end());
    int ans = 0;

    DisjointSet ds(V);

    for (auto i : edge)
    {
        int wt = i.first;
        int u = i.second.first;
        int v = i.second.second;

        if (ds.UltimateParent(u) != ds.UltimateParent(v))
        {
            ans += wt;
            ds.unionBySize(u, v);
        }
    }

    return ans;
}
