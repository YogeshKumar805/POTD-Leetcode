class Solution:
    def distributeCoins(self, root: Optional[TreeNode]) -> int:
        self.moves = 0
        
        def post_order(node):
            if not node:
                return 0
            
            left_balance = post_order(node.left)
            right_balance = post_order(node.right)
            
            # Total balance for the current node
            balance = node.val + left_balance + right_balance - 1
            
            # Add the number of moves required to balance the current node
            self.moves += abs(balance)
            
            # Return the balance to the parent node
            return balance
        
        post_order(root)
        return self.moves

