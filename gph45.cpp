// Connecting the graph(GFG)

#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
public:
	vector<int>rank,parent,size;
	DisjointSet(int n){
		rank.resize(n+1,0);
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n);
        int cnt=0;
        for(auto i:edge){
            int u=i[0];
            int v=i[1];
            
            if(ds.UltimateParent(u)==ds.UltimateParent(v)){
                cnt++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        int parCnt=0;
        for(int i=0;i<n;i++){
            if(ds.parent[i]==i){
                parCnt++;
            }
        }
        
        if((parCnt-1)<=cnt){
            return parCnt-1;
        }
        else{
            return -1;
        }
        
    }
};