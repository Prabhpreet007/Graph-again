// 743. Network Delay Time

class Solution {

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto i : times) {
            int u = i[0], v = i[1], wt = i[2];
            adj[u].push_back({v, wt});
        }
        vector<int> wt(n+1, 1e8);
        wt[k]=0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        pq.push({0,k});
        while(!pq.empty()){
            int currWt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto i:adj[node]){
                int newNode=i.first;
                int newWt=i.second;
                if(newWt+currWt<wt[newNode]){
                    wt[newNode]=newWt+currWt;
                    pq.push({wt[newNode],newNode});
                }
            }
        }



        int ans=0;
        for(int i=1;i<=n;i++){
            cout<<i<<" "<<wt[i]<<endl;
            if(wt[i]==1e8){
                ans=-1;
                break;
            }
            if(ans<wt[i]){
                ans=wt[i];
            }
        }

        return ans;
    }
};