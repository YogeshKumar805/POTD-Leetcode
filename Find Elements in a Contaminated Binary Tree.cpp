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
class FindElements {
public:
    unordered_set<int> elements;
    FindElements(TreeNode* root) {
        if(root != nullptr){
            queue<pair<int, TreeNode*>> q;
            q.push({0, root});
            elements.insert(0);
            while(!q.empty()){
                auto [x, node] = q.front();
                q.pop();
                if(node->left != nullptr){
                    q.push({2*x + 1, node->left});
                    elements.insert(2*x + 1);
                }
                if(node -> right != nullptr){
                    q.push({2*x + 2, node -> right});
                    elements.insert(2*x + 2);
                }
            }
        }
    }
    
    bool find(int target) {
        return elements.find(target) != elements.end();
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
