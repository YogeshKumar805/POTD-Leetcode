from collections import defaultdict

class Solution:
    def minimumDiameterAfterMerge(self, edges1: List[List[int]], edges2: List[List[int]]) -> int:
        def build_graph(edges):
            graph = defaultdict(list)
            for u, v in edges:
                graph[u].append(v)
                graph[v].append(u)
            return graph

        def find_tree_info(edges):
            graph = build_graph(edges)
            
            def dfs(node, parent):
                height, diameter = 0, 0
                max_height1, max_height2 = 0, 0
                for child in graph[node]:
                    if child != parent:
                        child_height, child_diameter = dfs(child, node)
                        diameter = max(diameter, child_diameter)
                        if child_height + 1 > max_height1:
                            max_height2 = max_height1
                            max_height1 = child_height + 1
                        elif child_height + 1 > max_height2:
                            max_height2 = child_height + 1
                
                diameter = max(diameter, max_height1 + max_height2)
                return max_height1, diameter

            _, diameter = dfs(0, -1)
            return diameter, min(len(graph) - 1, (diameter + 1) // 2)

        diameter1, height1 = find_tree_info(edges1)
        diameter2, height2 = find_tree_info(edges2)

        return max(diameter1, diameter2, height1 + height2 + 1)
