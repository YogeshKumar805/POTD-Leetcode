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
    int sum = 0; 
    void helper(TreeNode* rt, int n){
    
    if(rt == NULL){
    sum += 0;
    return;
    }
    n = (n*10) + rt->val;

    if(rt->left == NULL && rt->right == NULL){
    sum += n;
    return;
    }
 
    helper(rt->left, n);
    n /= 10;
    n = (n*10) + rt->val;
    helper(rt->right, n);
    }


    int sumNumbers(TreeNode* root) {
        helper(root, 0);
        return sum;
    }
};
