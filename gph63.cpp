// 332. Reconstruct Itinerary

// TLE
// PROPER DFS APPROACH (EXPLORING EVERY PATH)

class Solution {
public:

    vector<string>ans;


    void dfs(string init,unordered_map<string,set<string>>& adj, int n,vector<string>& res){
        res.push_back(init);
        auto nbr=adj[init];

        if(res.size()==n+1){
            ans=res;
            return;
        }

        for(auto i:nbr){
            adj[init].erase(i);
            dfs(i,adj,n,res);
            adj[init].insert(i);
        }

    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n=tickets.size();

        unordered_map<string,set<string>>adj;

        for(auto i:tickets){
            adj[i[0]].insert(i[1]);
        }

        string init="JFK";
        vector<string>res;
        dfs(init,adj,n,res);


        return ans;


    }
};







// Hierholzer's Algorithm (CP WLI NOTEBOOK ME THEORY HAI)
// Time: O(E log E)
// Space: O(V + E)


class Solution {
public:
    unordered_map<string, multiset<string>> adj;  // graph adjacency list
    vector<string> result; // final path

    void dfs(string src) {
        // Jab tak current node ke outgoing flights hain
        while (!adj[src].empty()) {
            // Lexicographically smallest destination
            string next = *adj[src].begin();
            adj[src].erase(adj[src].begin()); // edge use kar li
            dfs(next);
        }
        // Jab koi edge nahi bachi, node ko path me add kar do
        result.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Build the graph
        for (auto &t : tickets)
            adj[t[0]].insert(t[1]);

        // DFS from "JFK"
        dfs("JFK");

        // Reverse because nodes were added after exploring all edges
        reverse(result.begin(), result.end());
        return result;
    }
};