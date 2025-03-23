class Solution {
    class Pair implements Comparable<Pair>{
        int dest;
        long cost;
        public Pair(int d, long c){
            this.dest=d;
            this.cost=c;
        }
        @Override
        public int compareTo(Pair p2){
         return (int)(this.cost-p2.cost);
        }
    }
    public int countPaths(int n, int[][] roads) {

        long dist[]= new long[n];
        Arrays.fill(dist,Long.MAX_VALUE);
        dist[0]=0l;

        List<List<Pair>> adj= new ArrayList<>();

         for (int i = 0; i < n; i++) {
            adj.add(new ArrayList<>());
        }

        

        for(int i=0;i<roads.length;i++){
            adj.get(roads[i][0]).add(new Pair(roads[i][1],(long)roads[i][2]));
             adj.get(roads[i][1]).add(new Pair(roads[i][0],(long)roads[i][2]));
        }

        int ways[]= new int[n];
        ways[0]=1;

        PriorityQueue<Pair> pq= new PriorityQueue<>();
        pq.add(new Pair(0,0l));
        while(!pq.isEmpty()){
            Pair p = pq.remove();
            int curr=p.dest;
            for( Pair neigh : adj.get(curr)){
                long dis = neigh.cost;
                int node= neigh.dest;
                long ans= p.cost+dis;
                 
                if(ans<dist[node]){

                   dist[node]=ans;
                    ways[node]=ways[curr];
                     ways[node] %= 1000000007; 
                  pq.add(new Pair(node,dist[node]));
                }

                else if(ans==dist[node]){
                     ways[node]+=ways[curr];
                      ways[node] %= 1000000007; 
                }
            }
        }

       
        return ways[n-1];
        
    }

   
}
