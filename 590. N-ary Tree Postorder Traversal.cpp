/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
private:
    void helper(Node* root, vector<int> &ans){
        if(root){
            for(Node* child : root->children){
                helper(child, ans);
            }
            ans.push_back(root->val);
        }
    }
public:
    vector<int> postorder(Node* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Note
        // n - ary tree
        // n = ary tree is a tree where each node will have multiple children nodes. So, binary tree is also an n ary tree
        // The cap for the binary tree is the node can have atmost two children
        vector<int> ans;
        helper(root, ans);
        return ans;
    }
};
