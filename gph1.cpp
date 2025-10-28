// ADJACENCY LIST

#include<iostream>
#include<vector>
using namespace std;

// UNDIRECTED
//T.C= O(2E)

// int main(){
// int n,m;
// cin>>n>>m;

// vector<int>adjList[n+1];

// for(int i=0;i<m;i++){
//     int u,v;
//     cin>>u>>v;
//     adjList[u].push_back(v);
//     adjList[v].push_back(u);    
// }

//     return 0;
// }


// DIRECTED
// O(E)

int main(){
int n,m;
cin>>n>>m;

vector<int>adjList[n+1];

for(int i=0;i<m;i++){
    int u,v;
    cin>>u>>v;
    adjList[u].push_back(v);
    // adjList[v].push_back(u);    
}

    return 0;
}