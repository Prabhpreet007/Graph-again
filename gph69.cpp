// 1311. Get Watched Videos by Your Friends


class Solution {
public:
    vector<string> watchedVideosByFriends(
        vector<vector<string>>& watchedVideos,
        vector<vector<int>>& friends,
        int id,
        int level
    ) {
        int n = friends.size();
        vector<int> dist(n, -1);
        queue<int> q;

        // BFS start
        q.push(id);
        dist[id] = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto nei : friends[node]) {
                if (dist[nei] == -1) {
                    dist[nei] = dist[node] + 1;
                    q.push(nei);
                }
            }
        }

        // exact level wale friends ke videos
        unordered_map<string, int> freq;
        for (int i = 0; i < n; i++) {
            if (dist[i] == level) {
                for (auto &video : watchedVideos[i]) {
                    freq[video]++;
                }
            }
        }

        // sorting rules: frequency ↑ , name ↑
        vector<pair<int, string>> temp;
        for (auto &it : freq) {
            temp.push_back({it.second, it.first});
        }

        sort(temp.begin(), temp.end());

        vector<string> ans;
        for (auto &p : temp) {
            ans.push_back(p.second);
        }

        return ans;
    }
};
