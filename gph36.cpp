// 1976. Number of Ways to Arrive at Destination (gfg & lc)

// T.C=O(V logE)
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto i : roads) {
            int u = i[0];
            int v = i[1];
            int t = i[2];
            adj[u].push_back({v, t});
            adj[v].push_back({u, t});
        }
        vector<long long> cnt(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                       greater<pair<long long, int>>>q;
                       
        q.push({0, 0});

        vector<long long> time(n, 1e18);
        time[0] = 0;
        cnt[0] = 1;
        int mod = 1e9 + 7;

        while (!q.empty()) {
            long long t = q.top().first;
            int node = q.top().second;
            q.pop();

            for (auto i : adj[node]) {
                int newN = i.first;
                int newT = i.second;

                if (newT + t < time[newN]) {
                    time[newN] = newT + t;
                    cnt[newN] = cnt[node];
                    q.push({newT + t, newN});
                } else if (newT + t == time[newN]) {

                    cnt[newN] = (cnt[newN] + cnt[node]) % mod;
                }
            }
        }
        return cnt[n - 1] % mod;
    }
};

//modulo sirf cnt pe hoga dist pe ni
