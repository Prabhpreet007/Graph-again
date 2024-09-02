// Disjoint Set | Union by Size

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

	void unionByRank(int u,int v){
		int pu=UltimateParent(u);
		int pv=UltimateParent(v);
        if(pu==pv)return;
		int uRank=rank[pu];
		int vRank=rank[pv];

		if(uRank==vRank){
			parent[pv]=pu;
			rank[pu]++;
		}
		else if(uRank<vRank){
			parent[pu]=pv;
		}
		else if(uRank>vRank){
			parent[pv]=pu;
		}
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
            size[pv]+=size[pu];
        }
    }
};

int main(){
DisjointSet ds(7);
ds.unionBySize(1,2);
ds.unionBySize(2,3);
ds.unionBySize(4,5);
ds.unionBySize(6,7);
ds.unionBySize(5,6);
if(ds.UltimateParent(3)==ds.UltimateParent(7)){
	cout<<"Same"<<endl;
}
else{
	cout<<"Not Same"<<endl;
}

ds.unionBySize(3,7);

if(ds.UltimateParent(3)==ds.UltimateParent(7)){
	cout<<"Same"<<endl;
}
else{
	cout<<"Not Same"<<endl;
}
	return 0;
}