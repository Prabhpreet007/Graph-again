// dijkstra with set (its fastest)


    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        set<pair<int,int>>st;
        vector<int>distArr(V,1e9);
        distArr[S]=0;
        
        st.insert({0,S});
        while(!st.empty()){
            auto it=*(st.begin());
            int dist=it.first;
            int node=it.second;
            st.erase(it);
            
            for(auto i:adj[node]){
                int newNode=i[0];
                int newDist=i[1];
                
                if(dist+newDist<distArr[newNode]){
                    if(distArr[newNode]!=1e9){
                        st.erase({distArr[newNode],newNode});
                    }
                    distArr[newNode]=dist+newDist;
                    st.insert({distArr[newNode],newNode});
                }
            }
        }
        return distArr;
        
    }
    