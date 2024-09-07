class Solution:
    def isSubPath(self, head: Optional[ListNode], root: Optional[TreeNode]) -> bool:
        # Helper function to check if there's a matching path from this tree node downwards.
        def dfs(head: Optional[ListNode], node: Optional[TreeNode]) -> bool:
            if not head:  # If we've reached the end of the linked list, we found a match.
                return True
            if not node:  # If we've reached a null node in the tree, the path can't continue.
                return False
            if head.val != node.val:  # If the values don't match, return False.
                return False
            # Recur down the left and right subtrees to continue matching the next node in the list.
            return dfs(head.next, node.left) or dfs(head.next, node.right)
        
        # Main function to start the matching from any node in the tree.
        if not root:
            return False
        # Check if the current tree node starts a valid path or check its left and right children.
        return dfs(head, root) or self.isSubPath(head, root.left) or self.isSubPath(head, root.right)
