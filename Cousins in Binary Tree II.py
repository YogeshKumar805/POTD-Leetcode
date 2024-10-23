class Solution:
    def dfs(self, node):
        if not node: return
        # Root will always 0
        # Otherwise get the sum of its level minus the parent childs sum
        node.val = self.tbl[node.level] - node.parent.childs if node.parent else 0
        self.dfs(node.right)
        self.dfs(node.left)

    def replaceValueInTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        root.parent = None
        root.level = 0
        q = [root]
        self.tbl = defaultdict(int)
        # Precompute the level sum
        while q:
            node = q.pop()
            node.childs = 0 # Save the sum of current node childs
            self.tbl[node.level] += node.val # Save the level sum to a dict
            
            # Save parent node 
            # Increase level
            # Increase current node childs sum
            if node.left:
                node.left.parent = node 
                node.left.level = node.level + 1
                node.childs += node.left.val
                q.append(node.left)
            if node.right:
                node.right.parent = node
                node.right.level = node.level + 1
                node.childs += node.right.val
                q.append(node.right)
        # Travel to calculate the result
        self.dfs(root)
        return root
