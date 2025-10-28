
// 787. Cheapest Flights Within K Stops (GFG AND LC)



class Solution {
public class pair{
int first;
int second;
pair(int a,int b){
    this.first=a;
    this.second=b;
}
}

public class tuple{
int first;
int second;
int third;

tuple(int a,int b,int c){
    this.first=a;
    this.second=b;
    this.third=c;
}
}

    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int k) {
        ArrayList<ArrayList<pair>> adj=new ArrayList<>();
        for(int i=0;i<n;i++){
            adj.add(new ArrayList<>());
        }

        int r=flights.length;

        for(int i=0;i<r;i++){
            adj.get(flights[i][0]).add(new pair(flights[i][1],flights[i][2]));
        }
        Queue<tuple>q=new LinkedList<>();

        q.add(new tuple(0,src,0));
        int[] dist=new int[n];
        for(int i=0;i<n;i++){
            dist[i]=(int)1e9;
        }
        
        dist[src]=0;

        while(!q.isEmpty()){
            tuple it=q.peek();
            q.remove();
            int stops=it.first;
            int node=it.second;
            int cost=it.third;

            for(pair i:adj.get(node)){
                int adjNode=i.first;
                int wt=i.second;
                if(stops<=k && cost+wt<dist[adjNode]){
                    dist[adjNode]=cost+wt;
                    q.add(new tuple(stops+1,adjNode,dist[adjNode]));
                }
            }

        }

        if(dist[dst]==1e9)return -1;
        else return dist[dst];
    }
}