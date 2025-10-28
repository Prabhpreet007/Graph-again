// Account Merge (GFG & LEETCODE)


class DisjointSet{
public:
	vector<int>rank,parent,size;
	DisjointSet(int n){
		parent.resize(n+1);
        size.resize(n+1,1);
		for(int i=0;i<=n;++i){
			parent[i]=i;
		}
	}

	int UltimateParent(int n){
		if(parent[n]==n){
			return n;
		}
		return parent[n]=UltimateParent(parent[n]);
	}

    void unionBySize(int u,int v){
        int pu=UltimateParent(u);
        int pv=UltimateParent(v);

        if(pu==pv)return;
        int uSize=size[pu];
		int vSize=size[pv];
        if(uSize<vSize){
            parent[pu]=pv;
            size[pv]+=size[pu];
        }
        else{
            parent[pv]=pu;
            size[pu]+=size[pv];
        }
    }
};

class Solution {
  public:
    vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
        int n=accounts.size();
        unordered_map<string,int>mp;
        DisjointSet ds(n);
        
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])!=mp.end()){
                    ds.unionBySize(i,mp[accounts[i][j]]);
                }
                else{
                    mp[accounts[i][j]]=i;
                }
            }
        }
        
        vector<string> v[n];
        for(auto i:mp){
            string mail=i.first;
            int node=ds.UltimateParent(i.second);
            
            v[node].push_back(mail);
        }
        
        vector<vector<string>>ans;
        for(int i=0;i<n;i++){
            vector<string>temp;
            if(v[i].size()==0)continue;
            temp.push_back(accounts[i][0]);
            
            sort(v[i].begin(),v[i].end());
            
            for(auto j:v[i]){
                temp.push_back(j);
            }
                ans.push_back(temp);
        }
        return ans;
    }
};