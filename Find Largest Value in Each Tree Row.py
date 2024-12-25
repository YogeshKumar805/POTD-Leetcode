# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        # apply BFS
        result = []
        if root == None:
            return result
        
        process = [[root, 1]] # node and the level
        while len(process) > 0:
            front = process[0]
            node, level = front[0], front[1]
            process.pop(0)

            # based on the length check insert the node value
            if len(result) < level: # new level arrived
                result.append(node.val)
            else:
                result[level - 1] = max(result[level - 1], node.val)


            # insert the nodes in the process
            if node.left != None:
                process.append([node.left, level + 1])
            if node.right != None:
                process.append([node.right, level + 1])
            
        return result
            
            
