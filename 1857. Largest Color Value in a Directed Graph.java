class Node{
    int outDegreeCount;
    List<Node> parentNodes;
    int[] childColorCounts;
    char color;
    Node(char color){
        this.color = color;
        parentNodes = new LinkedList<>();
        childColorCounts = new int[26];
        childColorCounts[color - 97] ++;
    }
    public String toString(){
        return color+" ";
    }
}
class Solution {
    public int largestPathValue(String colors, int[][] edges) {
        if(edges.length == 0){
            return 1;
        }
        Map<Integer,Node> nodes = new HashMap<>();
        
        storeGraph(nodes, edges, colors);

        Queue<Node> queueNodes = new LinkedList<>();

        addZeroOutDegreeNodes(queueNodes, nodes, colors);
        int visitedNodeCount = queueNodes.size(), n = nodes.size();
        int maxColorValue = 0;

        while(!queueNodes.isEmpty()){
            int size = queueNodes.size();
            while(size -- > 0){
                Node node = queueNodes.poll();
                maxColorValue = Math.max(maxColorValue, node.childColorCounts[node.color - 97]);
                for(Node parentNode: node.parentNodes){
                    updateParentColorCounts(nodes, node, parentNode);
                    parentNode.outDegreeCount--;

                    if(parentNode.outDegreeCount == 0){
                        queueNodes.add(parentNode);
                        visitedNodeCount++;
                    }
                }
            }
        }

        return visitedNodeCount == n ? maxColorValue : -1;
    }
    private void storeGraph(Map<Integer,Node> nodes, int[][] edges, String colors){
        for(int[] edge: edges){
            Node a = nodes.getOrDefault(edge[0], new Node(colors.charAt(edge[0])));
            Node b = nodes.getOrDefault(edge[1], new Node(colors.charAt(edge[1])));
            nodes.putIfAbsent(edge[0], a);
            nodes.putIfAbsent(edge[1], b);
            a.outDegreeCount++;

            b.parentNodes.add(a);
        }
    }
    private void addZeroOutDegreeNodes(Queue<Node> queueNodes, Map<Integer,Node> nodes, String colors){
        for(Node node: nodes.values()){
            if(node.outDegreeCount == 0){
                queueNodes.add(node);
            }
        }
    }
    private void updateParentColorCounts(Map<Integer,Node> nodes, Node node, Node parentNode){
        for(int i = 0; i< 26;i++){
            parentNode.childColorCounts[i] = Math.max(parentNode.childColorCounts[i], node.childColorCounts[i]);
            if(i == parentNode.color - 97){
                parentNode.childColorCounts[i] = Math.max(parentNode.childColorCounts[i], node.childColorCounts[i]+1);
            }
        }
    }
}
