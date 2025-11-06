// Walls And Gates (C.N)
// t.c= n*m


#include <bits/stdc++.h> 
vector<vector<int>> wallsAndGates(vector<vector<int>> &a, int n, int m) {
    
    queue<pair<int,pair<int,int>>>q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]==0){
                q.push({0,{i,j}});
            }
        }
    }
    int x[4]={0,0,1,-1};
    int y[4]={1,-1,0,0};

    while(!q.empty()){
        auto front=q.front();
        q.pop();

        int wt=front.first;
        int r=front.second.first;
        int c=front.second.second;

        for(int i=0;i<4;i++){
            int newr=r+x[i];
            int newc=c+y[i];

            if(newr>=0 && newc>=0 && newr<n && newc<m && a[newr][newc]!=-1 
                && a[newr][newc]>wt+1){
                    a[newr][newc]=wt+1;
                    q.push({wt+1,{newr,newc}});
            }

        }
    }

    return a;
    
}