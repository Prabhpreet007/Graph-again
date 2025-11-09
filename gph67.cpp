// 934. Shortest Bridge

// TIME COMPLEXITY 
// DFS: O(n × m) to mark first island
// BFS: O(n × m) to expand
// Total: O(n × m)

class Solution {
public:
    int x[4] = {0, 0, 1, -1};
    int y[4] = {1, -1, 0, 0};
    void dfs(int r, int c, vector<vector<bool>>& vis,
             vector<vector<int>>& grid) {
        vis[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int newr = r + x[i];
            int newc = c + y[i];
            if (newr >= 0 && newc >= 0 && newr < grid.size() &&
                newc < grid[0].size() && grid[newr][newc] == 1 &&
                !vis[newr][newc]) {
                dfs(newr, newc, vis, grid);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        bool check = false;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    dfs(i, j, vis, grid);
                    check = true;
                    break;
                }
            }
            if (check)
                break;
        }

        queue<pair<int, pair<int, int>>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] && grid[i][j] == 1) {
                    q.push({0, {i, j}});
                }
            }
        }

        while (!q.empty()) {
            auto front = q.front();
            q.pop();
            int step = front.first;
            int r = front.second.first;
            int c = front.second.second;

            for (int i = 0; i < 4; i++) {
                int newr = r + x[i];
                int newc = c + y[i];
                if (newr >= 0 && newc >= 0 && newr < grid.size() &&
                    newc < grid[0].size() && !vis[newr][newc]) {
                    if (grid[newr][newc] == 1) {
                        return step;
                    } else {
                        vis[newr][newc] = true;
                        q.push({step+1,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};