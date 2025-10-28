// Alien Dictionary(GFG)



    vector<int> TopoSort(vector<int>adj[],int n){ 
        vector<int>inDeg(n,0);
        
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                inDeg[it]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<n;i++){
            if(inDeg[i]==0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int front=q.front();q.pop();
            ans.push_back(front);
            
            for(auto i:adj[front]){
                inDeg[i]--;
                if(inDeg[i]==0){
                    q.push(i);
                }
            }    
        }
        
        return ans;
        
    }
    
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            
            int len=min(s1.length(),s2.length());
            for(int i=0;i<len;i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
            
        }
        vector<int>topo=TopoSort(adj,K);
        string ans="";
        for(auto i:topo){
            ans+=char(i+'a');
        }
        return ans;
    }