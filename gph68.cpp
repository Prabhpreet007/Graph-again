// 802. Find Eventual Safe States

// time complexity : O(V+E)

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int>indeg(n);
        vector<int>adj[n];
        
        for(int i=0;i<n;i++){
            for(auto num:graph[i]){
                adj[num].push_back(i);
                indeg[i]++;
            }
        }
        
        queue<int>q;

        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();q.pop();
            ans.push_back(front);

            for(auto i:adj[front]){
                indeg[i]--;
                if(indeg[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};