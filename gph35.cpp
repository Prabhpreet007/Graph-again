// Minimum Multiplications to reach End(GFG)
// O(100000*N) in worst case
// here N is length of array 

    int minimumMultiplications(vector<int>& arr, int start, int end) {
        
        queue<pair<int,int>>q;
        vector<int>dist(100000,1e9);
        if(start==end)return 0;
        q.push({0,start});
        dist[start]=0;
        while(!q.empty()){
            auto front=q.front();q.pop();
            int steps=front.first;
            int num=front.second;
            
            
            for(auto i:arr){
                int x=(i*num)%100000;
                if(steps+1<dist[x]){
                    dist[x]=steps+1;
                    if(x==end)return steps+1;
                    q.push({steps+1,x});


                }
            }
        }
        return -1;
        
    }