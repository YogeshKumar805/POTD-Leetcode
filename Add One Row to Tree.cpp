/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // time/space: O(n)/O(h)
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        // base case
        if (depth == 1) {
            return new TreeNode(val, root, NULL);
        }

        // DFS
        helper(root, val, depth, 1);
        return root;
    }
private:
    void helper(TreeNode* node, int val, int depth, int curr_depth) {
        // terminate
        if (node == NULL) return;
        if (curr_depth == (depth - 1)) {
            node->left = new TreeNode(val, node->left, NULL);
            node->right = new TreeNode(val, NULL, node->right);
            return;
        }

        // enumerate
        helper(node->left, val, depth, curr_depth + 1);
        helper(node->right, val, depth, curr_depth + 1);
    }
};
