class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
            List<List<Integer>>g=new ArrayList<>();
            for(int i=0;i<n;i++)
            {
                g.add(new ArrayList<>());
            }
            for(int i=0;i<edges.length;i++)
            {
                g.get(edges[i][0]).add(edges[i][1]);
                g.get(edges[i][1]).add(edges[i][0]);
            }
            int c=0;
            boolean vis[]=new boolean[n];
            for(int i=0;i<n;i++)
            {
                if(!vis[i])
                {
                    Queue<Integer>q=new LinkedList<>();
                    q.offer(i);
                    List<Integer>li=new ArrayList<>();
                    vis[i]=true;
                    while(!q.isEmpty())
                    {
                        int x=q.poll();
                        li.add(x);
                        for(int  j:g.get(x))
                        {
                            if(!vis[j] )
                            {
                                q.offer(j);
                                vis[j]=true;
                            }
                        }
                    }
                    boolean flag=true;
                    for(int j:li)
                    {
                        if(g.get(j).size()!=li.size()-1)
                         {
                            flag=false;
                            break;
                         }
                    }
                    if(flag)
                     c++;
                }
            }
            return c;
    }
}
